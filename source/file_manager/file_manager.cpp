#include "file_manager.h"

void FileManager::setAppsPath(const std::string &path) {
    appsPath = path;
}

std::string FileManager::getAppsPath() {
    return appsPath;
}

void FileManager::setAppsIds(const std::vector<std::string> &IDs) {
    appsIDs = IDs;
}

int8_t FileManager::createRA(const std::string &appID, std::vector<RadioApp> &listOfApps) {
    for (auto &&app: listOfApps) {
        if (appID == app.getAppId()) {
            return static_cast<int8_t>(Installation::Codes::ALREADY_INSTALLED);
        }
    }

    if (isAppIDExist(appID)) {
        RadioApp app(appID, "1.0", RadioAppStatus::INSTALLED);
        listOfApps.push_back(app);
        return static_cast<int8_t>(Installation::Codes::OK);
    }

    return static_cast<int8_t>(Installation::Codes::NO_URA);
}

bool FileManager::isAppIDExist(const std::string &appID) {
    for (auto &&ID: appsIDs) {
        if (ID == appID) {
            return true;
        }
    }

    return false;
}