#include "administrator.h"

namespace CSL {
    int8_t Administrator::installRAReq(const std::string &appID, std::vector<RadioApp> &listOfApps,
                                       RCF::ConfigurationManager &configurationManager, FileManager &fileManager) {
        return configurationManager.installRAReq(appID, listOfApps, fileManager);
    }
}