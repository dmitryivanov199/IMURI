#ifndef IMURI_ADMINISTRATOR_H
#define IMURI_ADMINISTRATOR_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../../file_manager/file_manager.h"
#include "../../radio_app/radio_app.h"
#include "../../rcf/configuration_manager/configuration_manager.h"

namespace CSL {
    class Administrator {
    public:
        Administrator() = default;

        ~Administrator() = default;

        int8_t installRAReq(const std::string &appID, std::vector<RadioApp> &listOfApps,
                            RCF::ConfigurationManager &configurationManager, FileManager &fileManager);
    };
}

#endif //IMURI_ADMINISTRATOR_H