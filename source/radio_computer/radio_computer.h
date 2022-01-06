#ifndef IMURI_RADIO_COMPUTER_H
#define IMURI_RADIO_COMPUTER_H

#include "stdint.h"
#include <string>
#include <vector>

#include "../imuri/imuri.h"
#include "../radio_app/radio_app.h"

class RadioComputer : public IMURI {
private:
    std::string radioComputerID;
    std::vector<RadioApp> listOfRadioApps;

public:
    RadioComputer(const std::string &id, const std::vector<RadioApp> radioApps);

    ~RadioComputer() = default;
};

#endif //IMURI_RADIO_COMPUTER_H