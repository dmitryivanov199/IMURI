//
// Created by apt-15 on 30.07.2021.
//

#ifndef IMURI_RADIO_APP_H
#define IMURI_RADIO_APP_H

#include <string>
#include <vector>

#include "ra_option_id/ra_option_id.h"

class RadioApp {
private:
    std::string RadioAppID;
    std::string RAVersion;
    std::vector<std::pair<RAOptionID, std::string>> listOfSupportedOptions;

public:
    RadioApp(const std::string &id, const std::string &version,
             const std::vector<std::pair<RAOptionID, std::string>> &options);

    ~RadioApp();

    std::string getAppId();

    std::string getAppVersion();
};

#endif //IMURI_RADIO_APP_H
