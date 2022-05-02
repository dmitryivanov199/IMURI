#include "radio_app.h"

#include <utility>

RadioApp::RadioApp(std::string id, std::string version, const RadioAppStatus &status) :
        RadioAppID{std::move(id)},
        RAVersion{std::move(version)},
        radioAppStatus{status} {
    listOfSupportedOptions.clear();
    listOfParameters.clear();
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