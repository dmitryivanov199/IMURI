#include <iostream>
#include <stdint.h>
#include <string>

#include "source/radio_computer/radio_computer.h"


bool isRun(const std::string &cmd);

void printMenu();

void processCommand(const std::string &cmd, RadioComputer &radioComputer);

std::string inputAppID();

void parseInstallationCode(int8_t code);

int main() {
    RadioComputer radioComputer("RC1");

    std::string cmd = "";

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
        int8_t result = radioComputer.installRadioApps(<#initializer#>, inputAppID());
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

}