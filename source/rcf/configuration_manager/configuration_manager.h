#ifndef IMURI_CONFIGURATION_MANAGER_H
#define IMURI_CONFIGURATION_MANAGER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../../file_manager/file_manager.h"
#include "../../radio_app/radio_app.h"

namespace RCF {
    class ConfigurationManager {
    public:
        ConfigurationManager() = default;

        ~ConfigurationManager() = default;

        int8_t installRAReq(const std::string &appID, std::vector<RadioApp> &listOfApps, FileManager &fileManager);
    };
}

#endif //IMURI_CONFIGURATION_MANAGER_H