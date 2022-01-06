#include "radio_computer.h"

RadioComputer::RadioComputer(const std::string &id, const std::vector<RadioApp> radioApps) :
        radioComputerID(id),
        listOfRadioApps(radioApps) {
}