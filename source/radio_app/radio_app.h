#ifndef IMURI_RADIO_APP_H
#define IMURI_RADIO_APP_H

#include <string>
#include <vector>

#include "radio_app_status/radio_app_status.h"

class RadioApp {
private:
    std::string RadioAppID;
    std::string RAVersion;
    RadioAppStatus radioAppStatus;

public:
    RadioApp(std::string id, std::string version, const RadioAppStatus &status);

    ~RadioApp();

    bool operator==(const RadioApp &rhs) const;

    std::string getAppId();

    RadioAppStatus getAppStatus();

    void setAppStatus(const RadioAppStatus &status);
};

#endif //IMURI_RADIO_APP_H