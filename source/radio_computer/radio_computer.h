#ifndef IMURI_RADIO_COMPUTER_H
#define IMURI_RADIO_COMPUTER_H

#include <cstdint>
#include <string>
#include <vector>

#include "../imuri/imuri.h"
#include "../radio_app/radio_app.h"
#include "../rap/padding_bit.h"
#include "../rap/rap_header.h"
#include "../rap/ura_code_section.h"

class RadioComputer : public IMURI::IAdministrativeServices, public IMURI::IAccessControlServices {
private:
    std::string radioComputerId;

    const char *packPath = "/home/dmitry/projects/RAP/rap";
    const char *appPath = "/home/dmitry/projects/IMURI/ura";
    const char *receiverConfigPath = "/home/dmitry/projects/RAP/ura/RRS_Receiver";
    const char *transmitterConfigPath = "/home/dmitry/projects/RAP/ura/RRS_Transmitter";

    std::vector<RadioApp> listOfRadioApps;

public:
    explicit RadioComputer(std::string id);

    ~RadioComputer() = default;

    std::string getRadioComputerId();

    int8_t installRadioApps(const std::string &packId, const std::string &appId) override;

    int8_t uninstallRadioApps(const std::string &id) override;

    int8_t createRadioApps(const std::string &id) override;

    int8_t delRadioApps(const std::string &id) override;

    std::vector<RadioApp> getListOfRadioApps() override;

    int8_t activateRadioApps(const std::string &id) override;

private:
    bool isAppInstalled(const std::string &appId);

    bool isRapDownloaded(const std::string &packId);

    void getRapFileName(char *fileName, const std::string &packId);

    int8_t extractRap(const std::string &packId, const std::string &appId);

    static void printRapHeaderInfo(const RapHeader &header);

    int8_t extractUra(std::ifstream &pack, const std::string &appId);

    static void printRapDescriptorInfo(const RapDescriptor &descriptor);

    static void printDate(const Date &date);

    static void printRapStructureDescriptor(const RapStructureDescriptor &descriptor);

    static void printRadioLibDescriptorInfo(const RadioLibDescriptor &descriptor);

    static void printTargetPlatformDescriptorInfo(const TargetPlatformDescriptor &descriptor);

    static void printUraDescriptorInfo(const UraDescriptor &descriptor);

    static bool isNeededUra(const std::string &appId, std::array<unsigned char, 8> id);

    static std::string convertIdToString(std::array<unsigned char, 8> id);

    static std::string convertVersionToString(std::array<unsigned char, 4> version);

    void makeAppDirs(const std::string &appId);

    void putUraConfigs(const std::string &appId);

    RadioAppStatus getAppStatusById(const std::string &id);

    RadioApp getAppById(const std::string &id);

    void runAppPart(const std::string &id, const char *appPart);

    static std::string getUraPartPid();
};

#endif //IMURI_RADIO_COMPUTER_H