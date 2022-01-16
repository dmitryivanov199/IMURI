#ifndef IMURI_RADIO_COMPUTER_H
#define IMURI_RADIO_COMPUTER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../imuri/imuri.h"
#include "../radio_app/radio_app.h"
#include "../rap/rap_header.h"

class RadioComputer : public IMURI {
private:
    std::string radioComputerID;
    const char *rapPath = "/home/apt-15/Docs/rrs/rap/";
    const char *uraPath = "/home/apt-15/Docs/rrs/ura/";

    std::vector<RadioApp> listOfRadioApps;

public:
    RadioComputer(const std::string &ID);

    ~RadioComputer() = default;

    int8_t installRadioApps(const std::string &packID, const std::string &appID) override;

private:
    bool isAppInstalled(const std::string &appID);

    bool isRAPDownloaded(const std::string &packID);

    void getRAPFileName(char *fileName, const std::string &packID);

    int8_t extractRAP(const std::string &packID, const std::string &appID);

    static void printRAPHeaderInfo(const RAPHeader &header);

    static void printRAPDescriptorInfo(const RAPDescriptor &descriptor);

    static void printDate(const Date &date);

    static void printRAPStructureDescriptor(const RAPStructureDescriptor &descriptor);

    static void printRadioLibDescriptorInfo(const RadioLibDescriptor &descriptor);

    static void printTargetPlatformDescriptorInfo(const TargetPlatformDescriptor &descriptor);
};

#endif //IMURI_RADIO_COMPUTER_H