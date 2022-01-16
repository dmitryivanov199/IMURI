#ifndef IMURI_RADIO_COMPUTER_H
#define IMURI_RADIO_COMPUTER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../imuri/imuri.h"
#include "../radio_app/radio_app.h"

class RadioComputer : public IMURI {
private:
    std::string radioComputerID;
    const char *rapPath = "/home/apt-15/Docs/rrs/rap/";
    const char *uraPath = "/home/apt-15/Docs/rrs/ura/";

    std::vector<RadioApp> listOfRadioApps;

public:
    RadioComputer(const std::string &ID);

    ~RadioComputer() = default;

    int8_t installRadioApps(const std::string &rapID, const std::string &appID) override;

private:
    void extractRAP(const std::string &rapID, const std::string &appID);
};

#endif //IMURI_RADIO_COMPUTER_H