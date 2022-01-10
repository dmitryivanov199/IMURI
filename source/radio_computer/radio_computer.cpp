#include "radio_computer.h"

RadioComputer::RadioComputer(const std::string &id) :
        radioComputerID(id) {
    listOfRadioApps.clear();
}