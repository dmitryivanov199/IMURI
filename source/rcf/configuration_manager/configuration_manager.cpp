#include "configuration_manager.h"

namespace RCF {
    int8_t
    ConfigurationManager::installRAReq(const std::string &appID, std::vector<RadioApp> &listOfApps,
                                       FileManager &fileManager) {
        return fileManager.createRA(appID, listOfApps);
    }
}