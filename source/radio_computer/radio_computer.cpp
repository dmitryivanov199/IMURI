#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <utility>

#include "../error_codes/error_codes.h"
#include "../radio_app/radio_app_status/radio_app_status.h"
#include "radio_computer.h"

RadioComputer::RadioComputer(std::string id) :
        radioComputerId{std::move(id)} {
    listOfRadioApps.clear();
}

std::string RadioComputer::getRadioComputerId() {
    return radioComputerId;
}

int8_t RadioComputer::installRadioApps(const std::string &packId, const std::string &appId) {
    if (isAppInstalled(appId)) {
        return static_cast<int8_t>(Codes::Installation::ALREADY_INSTALLED);
    }

    if (isRapDownloaded(packId)) {
        return extractRap(packId, appId);
    }

    return static_cast<int8_t>(Codes::Installation::NO_RAP);
}

int8_t RadioComputer::uninstallRadioApps(const std::string &id) {
    if (isAppInstalled(id)) {
        if (getAppStatusById(id) == RadioAppStatus::ACTIVATED) {
            return static_cast<int8_t>(Codes::Uninstallation::ACTIVATED);
        }

        char cmd[100];
        strcpy(cmd, "\0");
        strcat(cmd, "rm -rf ");
        strcat(cmd, appPath);
        strcat(cmd, "/");
        strcat(cmd, id.c_str());
        system(cmd);

        RadioApp appToRemove = getAppById(id);
        listOfRadioApps.erase(std::remove(listOfRadioApps.begin(), listOfRadioApps.end(), appToRemove),
                              listOfRadioApps.end());

        return static_cast<int8_t>(Codes::Uninstallation::OK);
    }

    return static_cast<int8_t>(Codes::Uninstallation::NO_URA);
}

int8_t RadioComputer::createRadioApps(const std::string &id) {
    if (isAppInstalled(id)) {
        RadioAppStatus status = getAppStatusById(id);

        if (status == RadioAppStatus::ACTIVATED) {
            return static_cast<int8_t>(Codes::Instantiation::ACTIVATED);
        }

        if (status == RadioAppStatus::INSTANTIATED) {
            return static_cast<int8_t>(Codes::Instantiation::ALREADY_INSTANTIATED);
        }

        for (auto &app: listOfRadioApps) {
            if (app.getAppId() == id) {
                app.setAppStatus(RadioAppStatus::INSTANTIATED);
                break;
            }
        }

        return static_cast<int8_t>(Codes::Instantiation::OK);
    }

    return static_cast<int8_t>(Codes::Instantiation::NO_URA);
}

int8_t RadioComputer::delRadioApps(const std::string &id) {
    if (isAppInstalled(id)) {
        RadioAppStatus status = getAppStatusById(id);

        if (status == RadioAppStatus::ACTIVATED) {
            return static_cast<int8_t>(Codes::Deletion::ACTIVATED);
        }

        if (status == RadioAppStatus::INSTALLED) {
            return static_cast<int8_t>(Codes::Deletion::ALREADY_DELETED);
        }

        for (auto &app: listOfRadioApps) {
            if (app.getAppId() == id) {
                app.setAppStatus(RadioAppStatus::INSTALLED);
                break;
            }
        }

        return static_cast<int8_t>(Codes::Deletion::OK);
    }

    return static_cast<int8_t>(Codes::Deletion::NO_URA);
}

std::vector<RadioApp> RadioComputer::getListOfRadioApps() {
    return listOfRadioApps;
}

int8_t RadioComputer::activateRadioApps(const std::string &id) {
    if (isAppInstalled(id)) {
        RadioAppStatus status = getAppStatusById(id);

        if (status == RadioAppStatus::ACTIVATED) {
            return static_cast<int8_t>(Codes::Activation::ALREADY_ACTIVATED);
        }

        if (status == RadioAppStatus::INSTALLED) {
            return static_cast<int8_t>(Codes::Activation::NOT_INSTANTIATED);
        }

        for (auto &app: listOfRadioApps) {
            if (app.getAppId() == id) {
                runAppPart(id, "/receiver/receiver &");
                sleep(2);
                app.setReceiverPid(getUraPartPid());

                runAppPart(id, "/transmitter/transmitter 4455 &");
                sleep(2);
                app.setTransmitterPid(getUraPartPid());

                app.setAppStatus(RadioAppStatus::ACTIVATED);
                break;
            }
        }

        return static_cast<int8_t>(Codes::Activation::OK);
    }

    return static_cast<int8_t>(Codes::Activation::NO_URA);
}

bool RadioComputer::deactivateRadioApps(const std::string &id) {
    if (isAppInstalled(id)) {
        RadioAppStatus status = getAppStatusById(id);

        if (status == RadioAppStatus::ACTIVATED) {
            for (auto &app: listOfRadioApps) {
                if (app.getAppId() == id) {
                    char cmd[100];

                    strcpy(cmd, "\0");
                    strcat(cmd, "kill ");
                    strcat(cmd, app.getReceiverPid().c_str());
                    system(cmd);

                    strcpy(cmd, "\0");
                    strcat(cmd, "kill ");
                    strcat(cmd, app.getTransmitterPid().c_str());
                    system(cmd);

                    app.setAppStatus(RadioAppStatus::INSTALLED);
                    break;
                }
            }

            return true;
        }

        return false;
    }

    return false;
}

bool RadioComputer::isAppInstalled(const std::string &appId) {
    for (auto app: listOfRadioApps) {
        if (app.getAppId() == appId) {
            return true;
        }
    }

    return false;
}

bool RadioComputer::isRapDownloaded(const std::string &packId) {
    char fileName[50];
    getRapFileName(fileName, packId);
    std::ifstream pack(fileName, std::ios_base::in | std::ios_base::binary);

    if (pack.is_open()) {
        pack.close();
        return true;
    }

    return false;
}

void RadioComputer::getRapFileName(char *fileName, const std::string &packId) {
    strcpy(fileName, packPath);
    strcat(fileName, "/");
    strcat(fileName, packId.c_str());
    strcat(fileName, ".bin");
}

int8_t RadioComputer::extractRap(const std::string &packId, const std::string &appId) {
    std::cout << "Extracting RAP with ID " << packId << "..." << std::endl;

    char fileName[50];
    getRapFileName(fileName, packId);
    std::ifstream pack(fileName, std::ios_base::in | std::ios_base::binary);

    if (pack.is_open()) {
        RapHeader packHeader{};
        pack.read((char *) &packHeader, sizeof(packHeader));
        printRapHeaderInfo(packHeader);
        return extractUra(pack, appId);
    }

    return static_cast<int8_t>(Codes::Installation::BAD_FILE);
}

void RadioComputer::printRapHeaderInfo(const RapHeader &header) {
    std::cout << "----- RAP header -----" << std::endl;
    printRapDescriptorInfo(header.packDescriptor);
    std::cout << std::endl;
    printRapStructureDescriptor(header.packStructureDescriptor);
    std::cout << std::endl;
    printRadioLibDescriptorInfo(header.radioLibDescriptor);
    std::cout << std::endl;
    printTargetPlatformDescriptorInfo(header.targetPlatformDescriptor);
    std::cout << std::endl;
}

int8_t RadioComputer::extractUra(std::ifstream &pack, const std::string &appId) {
    uint64_t codeSectionSize = 0;
    pack.read((char *) &codeSectionSize, sizeof(codeSectionSize));

    std::cout << "----- URA code section -----" << std::endl;

    UraDescriptor descriptor{};
    pack.read((char *) &descriptor, sizeof(descriptor));
    printUraDescriptorInfo(descriptor);

    if (isNeededUra(appId, descriptor.appId)) {
        makeAppDirs(appId);

        PaddingBit bit{1};

        for (int i = 0; i < 2; i++) {
            pack.read((char *) &bit, sizeof(bit));

            UraComponentHeader header{};
            pack.read((char *) &header, sizeof(header));

            uint64_t appSize = 0;
            pack.read((char *) &appSize, sizeof(appSize));
            uint64_t uraBytesRead = 0;

            char fileName[100];
            strcpy(fileName, "\0");
            strcat(fileName, appPath);
            strcat(fileName, "/");
            strcat(fileName, appId.c_str());
            strcat(fileName, "/");

            if (bit.paddingBit == 1) {
                strcat(fileName, "receiver/receiver");
            } else {
                strcat(fileName, "transmitter/transmitter");
            }

            std::ofstream appFile(fileName, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

            while (uraBytesRead < appSize) {
                char byte;
                pack.get(byte);
                appFile.write((char *) &byte, sizeof(byte));
                uraBytesRead++;
            }

            char cmd[100];
            strcpy(cmd, "\0");
            strcat(cmd, "chmod +x ");
            strcat(cmd, appPath);
            strcat(cmd, "/");
            strcat(cmd, appId.c_str());
            strcat(cmd, "/");

            if (bit.paddingBit == 1) {
                strcat(cmd, "receiver/receiver");
            } else {
                strcat(cmd, "transmitter/transmitter");
            }

            system(cmd);
        }

        pack.close();

        putUraConfigs(appId);
        std::string version = convertVersionToString(descriptor.appVersion);
        RadioApp app{appId, version, RadioAppStatus::INSTALLED};
        listOfRadioApps.push_back(app);

        return static_cast<int8_t>(Codes::Installation::OK);
    }

    return static_cast<int8_t>(Codes::Installation::NO_URA);
}

void RadioComputer::printRapDescriptorInfo(const RapDescriptor &descriptor) {
    std::cout << "RAP ID: ";

    for (size_t i = 0; descriptor.packId.at(i) != '\0'; i++) {
        std::cout << descriptor.packId.at(i);
    }

    std::cout << std::endl << "RAP version: ";

    for (size_t i = 0; descriptor.packVersion.at(i) != '\0'; i++) {
        std::cout << descriptor.packVersion.at(i);
    }

    std::cout << std::endl << "RAP date: ";
    printDate(descriptor.packDate);
    std::cout << "RAP producer ID: " << static_cast<int>(descriptor.packProducerId) << std::endl;
}

void RadioComputer::printDate(const Date &date) {
    std::cout << static_cast<int>(date.day) << "." << static_cast<int>(date.month) << "."
              << static_cast<int>(date.year) << std::endl;
}

void RadioComputer::printRapStructureDescriptor(const RapStructureDescriptor &descriptor) {
    std::cout << "Manufacturer info flag: " << static_cast<int>(descriptor.manufacturerInfoFlag) << std::endl;
    std::cout << "Initial profile flag: " << static_cast<int>(descriptor.initialProfileFlag) << std::endl;
    std::cout << "RAP reserve flag: " << static_cast<int>(descriptor.packReserveFlag) << std::endl;
    std::cout << "Header reserve flag: " << static_cast<int>(descriptor.headerReserveFlag) << std::endl;
    std::cout << "Manufacturer info reserve flag: " << static_cast<int>(descriptor.manufacturerInfoReserveFlag)
              << std::endl;
    std::cout << "Security reserve flag: " << static_cast<int>(descriptor.securityReserveFlag) << std::endl;
    std::cout << "Reserve flags: " << static_cast<int>(descriptor.reserveFlags) << std::endl;
}

void RadioComputer::printRadioLibDescriptorInfo(const RadioLibDescriptor &descriptor) {
    std::cout << "Radio lib version: ";

    for (size_t i = 0; descriptor.radioLibVersion.at(i) != '\0'; i++) {
        std::cout << descriptor.radioLibVersion.at(i);
    }

    std::cout << std::endl << "Radio lib date: ";
    printDate(descriptor.radioLibDate);
}

void RadioComputer::printTargetPlatformDescriptorInfo(const TargetPlatformDescriptor &descriptor) {
    std::cout << "Target platform ID: " << static_cast<int>(descriptor.targetPlatformId) << std::endl;
    std::cout << "Reconfiguration class: " << static_cast<int>(descriptor.reconfigurationClass) << std::endl;
}

void RadioComputer::printUraDescriptorInfo(const UraDescriptor &descriptor) {
    std::cout << "URA ID: ";

    for (size_t i = 0; descriptor.appId.at(i) != '\0'; i++) {
        std::cout << descriptor.appId.at(i);
    }

    std::cout << std::endl << "URA version: ";

    for (size_t i = 0; descriptor.appVersion.at(i) != '\0'; i++) {
        std::cout << descriptor.appVersion.at(i);
    }

    std::cout << std::endl << "URA date: ";
    printDate(descriptor.appDate);
    std::cout << "URA producer ID: " << static_cast<int>(descriptor.appProducerId) << std::endl << std::endl;
}

bool RadioComputer::isNeededUra(const std::string &appId, std::array<unsigned char, 8> id) {
    std::string stringID = convertIdToString(id);
    return appId == stringID;
}

std::string RadioComputer::convertIdToString(std::array<unsigned char, 8> id) {
    std::string stringID;

    for (size_t i = 0; id.at(i) != '\0'; i++) {
        stringID += static_cast<char>(id.at(i));
    }

    return stringID;
}

std::string RadioComputer::convertVersionToString(std::array<unsigned char, 4> version) {
    std::string stringVersion;

    for (size_t i = 0; version.at(i) != '\0'; i++) {
        stringVersion += static_cast<char>(version.at(i));
    }

    return stringVersion;
}

void RadioComputer::makeAppDirs(const std::string &appId) {
    char cmd[100];

    strcpy(cmd, "\0");
    strcat(cmd, "mkdir ");
    strcat(cmd, appPath);
    strcat(cmd, "/");
    strcat(cmd, appId.c_str());
    system(cmd);

    strcat(cmd, "/");
    strcat(cmd, "receiver");
    system(cmd);

    strcpy(cmd, "\0");
    strcat(cmd, "mkdir ");
    strcat(cmd, appPath);
    strcat(cmd, "/");
    strcat(cmd, appId.c_str());
    strcat(cmd, "/");
    strcat(cmd, "transmitter");
    system(cmd);
}

void RadioComputer::putUraConfigs(const std::string &appId) {
    char cmd[150];

    strcpy(cmd, "\0");
    strcat(cmd, "cp -f ");
    strcat(cmd, receiverConfigPath);
    strcat(cmd, "/*.cfg ");
    strcat(cmd, appPath);
    strcat(cmd, "/");
    strcat(cmd, appId.c_str());
    strcat(cmd, "/receiver");
    system(cmd);

    strcpy(cmd, "\0");
    strcat(cmd, "cp -f ");
    strcat(cmd, transmitterConfigPath);
    strcat(cmd, "/*.cfg ");
    strcat(cmd, appPath);
    strcat(cmd, "/");
    strcat(cmd, appId.c_str());
    strcat(cmd, "/transmitter");
    system(cmd);
}

RadioAppStatus RadioComputer::getAppStatusById(const std::string &id) {
    for (auto app: listOfRadioApps) {
        if (app.getAppId() == id) {
            return app.getAppStatus();
        }
    }

    return RadioAppStatus::NOT_FOUND;
}

RadioApp RadioComputer::getAppById(const std::string &id) {
    for (auto app: listOfRadioApps) {
        if (app.getAppId() == id) {
            return app;
        }
    }

    return RadioApp{"", "", RadioAppStatus::NOT_FOUND};
}

void RadioComputer::runAppPart(const std::string &id, const char *appPart) {
    char cmd[100];

    strcpy(cmd, "\0");
    strcat(cmd, appPath);
    strcat(cmd, "/");
    strcat(cmd, id.c_str());
    strcat(cmd, appPart);
    system(cmd);
}

std::string RadioComputer::getUraPartPid() {
    std::ifstream pidFile("./Pids_Storage.txt", std::ios::in);

    std::string pid;
    char symbol;

    while (!pidFile.eof()) {
        symbol = static_cast<char>(pidFile.get());

        if (symbol >= '0' && symbol <= '9') {
            pid += symbol;
        } else {
            break;
        }
    }

    pidFile.close();
    return pid;
}