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

std::string RadioApp::getReceiverPid() {
    return receiverPid;
}

std::string RadioApp::getTransmitterPid() {
    return transmitterPid;
}

void RadioApp::setAppStatus(const RadioAppStatus &status) {
    radioAppStatus = status;
}

void RadioApp::setReceiverPid(const std::string &pid) {
    receiverPid = pid;
}

void RadioApp::setTransmitterPid(const std::string &pid) {
    transmitterPid = pid;
}