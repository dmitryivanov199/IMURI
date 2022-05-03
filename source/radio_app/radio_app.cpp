#include "radio_app.h"

#include <utility>

RadioApp::RadioApp(std::string id, std::string version, const RadioAppStatus &status) :
        RadioAppID{std::move(id)},
        RAVersion{std::move(version)},
        radioAppStatus{status} {
}

RadioApp::~RadioApp() = default;

bool RadioApp::operator==(const RadioApp &rhs) const {
    if (this == &rhs) {
        return true;
    }

    return this->RadioAppID == rhs.RadioAppID && this->RAVersion == rhs.RAVersion &&
           this->radioAppStatus == rhs.radioAppStatus;
}

std::string RadioApp::getAppId() {
    return RadioAppID;
}

std::string RadioApp::getAppVersion() {
    return RAVersion;
}

RadioAppStatus RadioApp::getAppStatus() {
    return radioAppStatus;
}

void RadioApp::setAppStatus(const RadioAppStatus &status) {
    radioAppStatus = status;
}