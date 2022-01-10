#include "../radio_app/radio_app_status/radio_app_status.h"
#include "radio_computer.h"

RadioComputer::RadioComputer(const std::string &ID) :
        radioComputerID(ID) {
    listOfRadioApps.clear();

    fileManager.setAppsPath("/home/apt-15/Docs/ura/For_Dmitry/");
    std::vector<std::string> IDs;
    IDs.push_back("URA1");
    fileManager.setAppsIds(IDs);
}

std::string RadioComputer::getAppsPath() {
    return fileManager.getAppsPath();
}

int8_t RadioComputer::installRadioApps(const std::string &appID) {
    return administrator.installRAReq(appID, listOfRadioApps, configurationManager, fileManager);
}