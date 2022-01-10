#ifndef IMURI_RADIO_COMPUTER_H
#define IMURI_RADIO_COMPUTER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../csl/administrator/administrator.h"
#include "../file_manager/file_manager.h"
#include "../imuri/imuri.h"
#include "../radio_app/radio_app.h"
#include "../rcf/configuration_manager/configuration_manager.h"

class RadioComputer : public IMURI {
private:
    std::string radioComputerID;
    std::vector<RadioApp> listOfRadioApps;

    CSL::Administrator administrator;

    RCF::ConfigurationManager configurationManager;

    FileManager fileManager;

public:
    RadioComputer(const std::string &ID);

    ~RadioComputer() = default;

    std::string getAppsPath();

    int8_t installRadioApps(const std::string &appID) override;
};

#endif //IMURI_RADIO_COMPUTER_H