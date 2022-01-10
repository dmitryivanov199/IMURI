#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>

#include "source/file_manager/file_manager.h"
#include "source/radio_computer/radio_computer.h"

bool isAppExist(const std::string &appPath);

bool isRun(const std::string &cmd);

void printMenu();

void processCommand(const std::string &cmd, RadioComputer &radioComputer);

std::string inputAppID();

void parseInstallationCode(int8_t code);

int main(int argc, char *argv[]) {
    RadioComputer radioComputer("RC1");

    if (isAppExist(radioComputer.getAppsPath())) {
        std::string cmd = "";

        while (isRun(cmd)) {
            printMenu();
            std::cin >> cmd;
            processCommand(cmd, radioComputer);
        }

        return 0;
    }

    std::cout << "There is no app in path";
    return -1;
}

bool isAppExist(const std::string &appPath) {
    std::ifstream fin(appPath + "RRS_Receiver/RRS_Receiver");

    if (fin.is_open()) {
        fin.close();
        fin.open(appPath + "RRS_Transmitter/RRS_Transmitter");

        if (fin.is_open()) {
            fin.close();
            fin.open(appPath + "TestObject2/TestObject2");

            if (fin.is_open()) {
                fin.close();
                fin.open(appPath + "URA/URA");

                if (fin.is_open()) {
                    return true;
                }

                return false;
            }

            return false;
        }

        return false;
    }

    return false;
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
        int8_t result = radioComputer.installRadioApps(inputAppID());
        parseInstallationCode(result);
    }
}

std::string inputAppID() {
    std::cout << "Input URA ID" << std::endl;
    std::cout << "> ";
    std::string ID;
    std::cin >> ID;
    return ID;
}

void parseInstallationCode(int8_t code) {
    switch (static_cast<Installation::Codes>(code)) {
        case Installation::Codes::OK:
            std::cout << "URA has been installed successfully" << std::endl;
            break;
        case Installation::Codes::NO_URA:
            std::cout << "There is no URA with such ID" << std::endl;
            break;
        case Installation::Codes::ALREADY_INSTALLED:
            std::cout << "This URA had already been installed" << std::endl;
            break;
    }
}