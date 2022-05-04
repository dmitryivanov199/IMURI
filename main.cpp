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

void parseUninstallationCode(int8_t code);

void parseInstantiationCode(int8_t code);

void parseDeletionCode(int8_t code);

void printListOfApps(const std::vector<RadioApp> &appsList);

void parseActivationCode(int8_t code);

int main() {
    RadioComputer radioComputer("RC1");
    std::cout << "Radio computer ID: " << radioComputer.getRadioComputerId() << std::endl;

    std::string cmd;

    while (isRun(cmd)) {
        printMenu();
        std::cin >> cmd;
        processCommand(cmd, radioComputer);
    }

    return 0;
}

bool isRun(const std::string &cmd) {
    return !(cmd == "7");
}

void printMenu() {
    std::cout << std::endl << "--------------------" << std::endl;
    std::cout << "1 - Install URA" << std::endl;
    std::cout << "2 - Uninstall URA" << std::endl;
    std::cout << "3 - Create instance of URA" << std::endl;
    std::cout << "4 - Delete instance of URA" << std::endl;
    std::cout << "5 - Get URAs list" << std::endl;
    std::cout << "6 - Activate URA" << std::endl;
    std::cout << "7 - Exit" << std::endl;
    std::cout << "> ";
}

void processCommand(const std::string &cmd, RadioComputer &radioComputer) {
    if (cmd == "1") {
        int8_t result = radioComputer.installRadioApps(inputID("Input RAP ID"), inputID("Input URA ID"));
        parseInstallationCode(result);
    } else if (cmd == "2") {
        int8_t result = radioComputer.uninstallRadioApps(inputID("Input URA ID"));
        parseUninstallationCode(result);
    } else if (cmd == "3") {
        int8_t result = radioComputer.createRadioApps(inputID("Input URA ID"));
        parseInstantiationCode(result);
    } else if (cmd == "4") {
        int8_t result = radioComputer.delRadioApps(inputID("Input URA ID"));
        parseDeletionCode(result);
    } else if (cmd == "5") {
        std::vector<RadioApp> appsList = radioComputer.getListOfRadioApps();
        printListOfApps(appsList);
    } else if (cmd == "6") {
        int8_t result = radioComputer.activateRadioApps(inputID("Input URA ID"));
        parseActivationCode(result);
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
            std::cout << "URA had already been installed" << std::endl;
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

void parseUninstallationCode(int8_t code) {
    switch (code) {
        case static_cast<int8_t>(Codes::Uninstallation::OK): {
            std::cout << "URA has been uninstalled" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Uninstallation::NO_URA): {
            std::cout << "There is no installed URA with such ID" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Uninstallation::ACTIVATED): {
            std::cout << "This URA is activated" << std::endl;
            break;
        }

        default:
            break;
    }
}

void parseInstantiationCode(int8_t code) {
    switch (code) {
        case static_cast<int8_t>(Codes::Instantiation::OK): {
            std::cout << "URA instance has been created" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Instantiation::NO_URA): {
            std::cout << "There is no installed URA with such ID" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Instantiation::ACTIVATED): {
            std::cout << "This URA is activated" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Instantiation::ALREADY_INSTANTIATED): {
            std::cout << "URA instance had already been created" << std::endl;
            break;
        }

        default:
            break;
    }
}

void parseDeletionCode(int8_t code) {
    switch (code) {
        case static_cast<int8_t>(Codes::Deletion::OK): {
            std::cout << "URA instance has been deleted" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Deletion::NO_URA): {
            std::cout << "There is no installed URA with such ID" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Deletion::ACTIVATED): {
            std::cout << "This URA is activated" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Deletion::ALREADY_DELETED): {
            std::cout << "There is no instance of this URA" << std::endl;
            break;
        }

        default:
            break;
    }
}

void printListOfApps(const std::vector<RadioApp> &appsList) {
    if (appsList.empty()) {
        std::cout << "List of apps is empty" << std::endl;
        return;
    }

    std::cout << "----- List of apps -----" << std::endl << std::endl;

    for (auto app: appsList) {
        std::cout << "URA ID: " << app.getAppId() << std::endl;
        std::cout << "URA version: " << app.getAppVersion() << std::endl;

        switch (static_cast<int8_t>(app.getAppStatus())) {
            case static_cast<int8_t>(RadioAppStatus::INSTALLED): {
                std::cout << "Status: installed" << std::endl;
                break;
            }

            case static_cast<int8_t>(RadioAppStatus::INSTANTIATED): {
                std::cout << "Status: instance created" << std::endl;
                break;
            }

            case static_cast<int8_t>(RadioAppStatus::ACTIVATED): {
                std::cout << "Status: activated" << std::endl;
                break;
            }

            default:
                break;
        }

        std::cout << std::endl;
    }
}

void parseActivationCode(int8_t code) {
    switch (code) {
        case static_cast<int8_t>(Codes::Activation::OK): {
            std::cout << "URA has been activated" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Activation::NO_URA): {
            std::cout << "There is no installed URA with such ID" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Activation::ALREADY_ACTIVATED): {
            std::cout << "This URA had already been activated" << std::endl;
            break;
        }

        case static_cast<int8_t>(Codes::Activation::NOT_INSTANTIATED): {
            std::cout << "The creation of instance for this URA hadn't been made" << std::endl;
            break;
        }

        default:
            break;
    }
}