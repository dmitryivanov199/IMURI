#ifndef IMURI_RADIO_APP_H
#define IMURI_RADIO_APP_H

#include <string>
#include <vector>

#include "ra_option/ra_option.h"
#include "radio_app_status/radio_app_status.h"

class RadioApp {
private:
    std::string RadioAppID;
    std::string RAVersion;
    RadioAppStatus radioAppStatus;
    std::vector<RAOption<double>> listOfSupportedOptions;

public:
    RadioApp(const std::string &id, const std::string &version, const RadioAppStatus &status,
             const std::vector<RAOption<double>> &options);

    ~RadioApp();

    std::string getAppId();

    std::string getAppVersion();

    RadioAppStatus getAppStatus();
};

#endif //IMURI_RADIO_APP_H
