#ifndef IMURI_ADMINISTRATIVE_SERVICES_H
#define IMURI_ADMINISTRATIVE_SERVICES_H

#include <cstdint>
#include <string>
#include <vector>

#include "../radio_app/ra_parameter/ra_parameter.h"
#include "../radio_app/radio_app.h"

class IAdministrativeServices {
    virtual int8_t installRadioApps(const std::string &packID, const std::string &appID) = 0;

//    virtual int8_t uninstallRadioApps(const std::string &ID) = 0;

//    virtual int8_t createRadioApps(const std::string &ID) = 0;

//    virtual int8_t delRadioApps(const std::string &ID) = 0;

//    virtual int8_t updateRadioApps(const std::string &ID) = 0;

//    virtual std::vector<RadioAppParameter<double>> getRadioAppParameters(const std::string &ID) = 0;

//    virtual bool setRadioAppParameters(const std::string &ID, const std::vector<RadioAppParameter<double>> &parameters) = 0;

//    virtual std::vector<RadioApp> getListOfRadioApps() = 0;
};

#endif //IMURI_ADMINISTRATIVE_SERVICES_H