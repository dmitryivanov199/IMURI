//
// Created by apt-15 on 30.07.2021.
//

#include "radio_app.h"

RadioApp::RadioApp(const std::string &id, const std::string &version,
                   const std::vector<std::pair<RAOptionID, std::string>> &options) {
    RadioAppID = id;
    RAVersion = version;
    listOfSupportedOptions = options;
}

RadioApp::~RadioApp() = default;

std::string RadioApp::getAppId() {
    return RadioAppID;
}

std::string RadioApp::getAppVersion() {
    return RAVersion;
}