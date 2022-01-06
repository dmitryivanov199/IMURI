#include "radio_app.h"

RadioApp::RadioApp(const std::string &id, const std::string &version, const RadioAppStatus &status,
                   const std::vector<std::pair<RAOptionID, std::string>> &options) :
        RadioAppID(id),
        RAVersion(version),
        radioAppStatus(status),
        listOfSupportedOptions(options) {

}

RadioApp::~RadioApp() = default;

std::string RadioApp::getAppId() {
    return RadioAppID;
}

std::string RadioApp::getAppVersion() {
    return RAVersion;
}

RadioAppStatus RadioApp::getAppStatus() {
    return radioAppStatus;
}