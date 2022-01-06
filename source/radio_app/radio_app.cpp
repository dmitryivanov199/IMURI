#include "radio_app.h"

RadioApp::RadioApp(const std::string &id, const std::string &version, const RadioAppStatus &status,
                   const std::vector<RAOption<double>> &options,
                   const std::vector<RadioAppParameter<double>> &parameters) :
        RadioAppID(id),
        RAVersion(version),
        radioAppStatus(status),
        listOfSupportedOptions(options),
        listOfParameters(parameters) {
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