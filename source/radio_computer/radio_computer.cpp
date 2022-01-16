#include "../radio_app/radio_app_status/radio_app_status.h"
#include "radio_computer.h"

RadioComputer::RadioComputer(const std::string &ID) :
        radioComputerID{ID} {
    listOfRadioApps.clear();
}

int8_t RadioComputer::installRadioApps(const std::string &rapID, const std::string &appID) {

}

void RadioComputer::extractRAP(const std::string &rapID, const std::string &appID) {

}