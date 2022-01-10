#ifndef IMURI_FILE_MANAGER_H
#define IMURI_FILE_MANAGER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../radio_app/radio_app.h"

namespace Installation {
    enum class Codes {
        OK,
        NO_URA,
        ALREADY_INSTALLED
    };
}

class FileManager {
private:
    std::string appsPath;
    std::vector<std::string> appsIDs;

public:
    FileManager() = default;

    ~FileManager() = default;

    void setAppsPath(const std::string &path);

    std::string getAppsPath();

    void setAppsIds(const std::vector<std::string> &IDs);

    int8_t createRA(const std::string &appID, std::vector<RadioApp> &listOfApps);

private:
    bool isAppIDExist(const std::string &appID);
};

#endif //IMURI_FILE_MANAGER_H