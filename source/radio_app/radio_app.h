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

    std::string receiverPid;
    std::string transmitterPid;

public:
    RadioApp(std::string id, std::string version, const RadioAppStatus &status);

    ~RadioApp();

    bool operator==(const RadioApp &rhs) const;

    std::string getAppId();

    std::string getAppVersion();

    RadioAppStatus getAppStatus();

    std::string getReceiverPid();

    std::string getTransmitterPid();

    void setAppStatus(const RadioAppStatus &status);

    void setReceiverPid(const std::string &pid);

    void setTransmitterPid(const std::string &pid);
};

#endif //IMURI_RADIO_APP_H