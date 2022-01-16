#ifndef IMURI_URA_CODE_SECTION_H
#define IMURI_URA_CODE_SECTION_H

#include <array>
#include <cstdint>

#include "date.h"

struct URADescriptor {
    std::array<unsigned char, 8> appID;
    std::array<unsigned char, 4> appVersion;
    Date appDate;
    uint8_t appProducerID;
};

struct URAComponentHeader {
    std::array<unsigned char, 8> appComponentID;
    uint8_t appComponentCodeType;
    uint8_t HWComponentID;
};

#endif //IMURI_URA_CODE_SECTION_H