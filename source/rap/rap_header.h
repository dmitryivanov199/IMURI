#ifndef IMURI_RAP_HEADER_H
#define IMURI_RAP_HEADER_H

#include <array>

#include "date.h"

struct RAPDescriptor {
    std::array<unsigned char, 8> packID;
    std::array<unsigned char, 4> packVersion;
    Date packDate;
    uint8_t packProducerID;
};

struct RAPStructureDescriptor {
    uint8_t manufacturerInfoFlag: 1;
    uint8_t initialProfileFlag: 1;
    uint8_t packReserveFlag: 1;
    uint8_t headerReserveFlag: 1;
    uint8_t manufacturerInfoReserveFlag: 1;
    uint8_t securityReserveFlag: 1;
    uint8_t reserveFlags: 2;
};

struct RadioLibDescriptor {
    std::array<unsigned char, 4> radioLibVersion;
    Date radioLibDate;
};

struct TargetPlatformDescriptor {
    uint8_t targetPlatformID;
    uint8_t reconfigurationClass;
};

struct RAPHeader {
    RAPDescriptor packDescriptor;
    RAPStructureDescriptor packStructureDescriptor;
    RadioLibDescriptor radioLibDescriptor;
    TargetPlatformDescriptor targetPlatformDescriptor;
};

#endif //IMURI_RAP_HEADER_H