#include <iostream>
#include <cstdint>
#include <string>

#include "source/error_codes/error_codes.h"
#include "source/radio_computer/radio_computer.h"

bool isRun(const std::string &cmd);

void printMenu();

void processCommand(const std::string &cmd, RadioComputer &radioComputer);

std::string inputID(const std::string &message);

void parseInstallationCode(int8_t code);

int main() {
    RadioComputer radioComputer("RC1");

    std::string cmd;

    while (isRun(cmd)) {
        printMenu();
        std::cin >> cmd;
        processCommand(cmd, radioComputer);
    }

    return 0;
}

bool isRun(const std::string &cmd) {
    return !(cmd == "2");
}

void printMenu() {
    std::cout << "1 - Install URA" << std::endl;
    std::cout << "2 - Exit" << std::endl;
    std::cout << "> ";
}

void processCommand(const std::string &cmd, RadioComputer &radioComputer) {
    if (cmd == "1") {
        int8_t result = radioComputer.installRadioApps(inputID("Input RAP ID"), inputID("Input URA ID"));
        parseInstallationCode(result);
    }
}

std::string inputID(const std::string &message) {
    std::cout << message << std::endl;
    std::cout << "> ";
    std::string ID;
    std::cin >> ID;
    return ID;
}

void parseInstallationCode(int8_t code) {
    switch (code) {
        case static_cast<int8_t>(Codes::Installation::OK): {
            std::cout << "URA has been installed" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Installation::NO_RAP): {
            std::cout << "There is no RAP with such ID" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Installation::NO_URA): {
            std::cout << "There is no URA with such ID in RAP" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Installation::ALREADY_INSTALLED): {
            std::cout << "URA had been already installed" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Installation::BAD_FILE): {
            std::cout << "RAP file cannot be opened" << std::endl;
            break;
        }

        default:
            break;
    }
}