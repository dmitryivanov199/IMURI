#ifndef IMURI_IMURI_H
#define IMURI_IMURI_H

#include "../radio_app/radio_app.h"

class IMURI {
public:
    class IAdministrativeServices {
    public:
        virtual int8_t installRadioApps(const std::string &packId, const std::string &appId) = 0;

        virtual int8_t uninstallRadioApps(const std::string &id) = 0;

        virtual int8_t createRadioApps(const std::string &id) = 0;

//        virtual int8_t delRadioApps(const std::string &id) = 0;
//
//        virtual std::vector<RadioApp> getListOfRadioApps() = 0;
    };

    class IAccessControlServices {
    public:
//        virtual int8_t activateRadioApps(const std::string &id) = 0;
//
//        virtual bool deactivateRadioApps(const std::string &id) = 0;
    };
};

#endif //IMURI_IMURI_H