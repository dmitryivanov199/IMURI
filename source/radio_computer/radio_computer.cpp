#include <cstring>
#include <fstream>
#include <iostream>

#include "../error_codes/error_codes.h"
#include "../radio_app/radio_app_status/radio_app_status.h"
#include "radio_computer.h"

RadioComputer::RadioComputer(const std::string &ID) :
        radioComputerID{ID} {
    listOfRadioApps.clear();
}

int8_t RadioComputer::installRadioApps(const std::string &packID, const std::string &appID) {
    if (isAppInstalled(appID)) {
        return static_cast<int8_t>(Codes::Installation::ALREADY_INSTALLED);
    }

    if (isRAPDownloaded(packID)) {
        return extractRAP(packID, appID);
    }

    return static_cast<int8_t>(Codes::Installation::NO_RAP);
}

bool RadioComputer::isAppInstalled(const std::string &appID) {
    for (auto app: listOfRadioApps) {
        if (app.getAppId() == appID) {
            return true;
        }
    }

    return false;
}

bool RadioComputer::isRAPDownloaded(const std::string &packID) {
    char fileName[50];
    getRAPFileName(fileName, packID);
    std::ifstream pack(fileName, std::ios_base::in | std::ios_base::binary);

    if (pack.is_open()) {
        pack.close();
        return true;
    }

    return false;
}

void RadioComputer::getRAPFileName(char *fileName, const std::string &packID) {
    strcpy(fileName, rapPath);
    strcat(fileName, "/");
    strcat(fileName, packID.c_str());
    strcat(fileName, ".bin");
}

int8_t RadioComputer::extractRAP(const std::string &packID, const std::string &appID) {
    std::cout << "Extracting RAP with ID " << packID << "..." << std::endl;

    char fileName[50];
    getRAPFileName(fileName, packID);
    std::ifstream pack(fileName, std::ios_base::in | std::ios_base::binary);

    if (pack.is_open()) {
        RAPHeader packHeader{};
        pack.read((char *) &packHeader, sizeof(packHeader));
        printRAPHeaderInfo(packHeader);

        pack.close();
    }

    return static_cast<int8_t>(Codes::Installation::BAD_FILE);
}

void RadioComputer::printRAPHeaderInfo(const RAPHeader &header) {
    std::cout << "----- RAP header -----" << std::endl;
    printRAPDescriptorInfo(header.packDescriptor);
    std::cout << std::endl;
    printRAPStructureDescriptor(header.packStructureDescriptor);
    std::cout << std::endl;
    printRadioLibDescriptorInfo(header.radioLibDescriptor);
    std::cout << std::endl;
    printTargetPlatformDescriptorInfo(header.targetPlatformDescriptor);
    std::cout << std::endl;
}

void RadioComputer::printRAPDescriptorInfo(const RAPDescriptor &descriptor) {
    std::cout << "RAP ID: ";

    for (size_t i = 0; descriptor.packID.at(i) != '\0'; i++) {
        std::cout << descriptor.packID.at(i);
    }

    std::cout << std::endl << "RAP version: ";

    for (size_t i = 0; descriptor.packVersion.at(i) != '\0'; i++) {
        std::cout << descriptor.packVersion.at(i);
    }

    std::cout << std::endl << "RAP date: ";
    printDate(descriptor.packDate);
    std::cout << "RAP producer ID: " << static_cast<int>(descriptor.packProducerID) << std::endl;
}

void RadioComputer::printDate(const Date &date) {
    std::cout << static_cast<int>(date.day) << "." << static_cast<int>(date.month) << "."
              << static_cast<int>(date.year) << std::endl;
}

void RadioComputer::printRAPStructureDescriptor(const RAPStructureDescriptor &descriptor) {
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
    std::cout << std::endl << "Radio lib version: ";

    for (size_t i = 0; descriptor.radioLibVersion.at(i) != '\0'; i++) {
        std::cout << descriptor.radioLibVersion.at(i);
    }

    std::cout << std::endl << "Radio lib date: ";
    printDate(descriptor.radioLibDate);
}

void RadioComputer::printTargetPlatformDescriptorInfo(const TargetPlatformDescriptor &descriptor) {
    std::cout << "Target platform ID: " << static_cast<int>(descriptor.targetPlatformID) << std::endl;
    std::cout << "Reconfiguration class: " << static_cast<int>(descriptor.reconfigurationClass) << std::endl;
}