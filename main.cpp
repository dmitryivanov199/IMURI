#include <iostream>

#include "source/md5/md5.h"

int main() {
    std::string hash = Md5::getMd5Hash(
            "a                             a        &Y&G                    ((((((((((((((((9999999999                 yyyyyyy");
    std::string rightAnswer = "7bc62872e0227a31566ca77de3a925f4";

    std::cout << "Awaited: " << rightAnswer << std::endl;
    std::cout << "Result: " << hash << std::endl;

    if (hash == rightAnswer) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
