#ifndef IMURI_RAP_HEADER_H
#define IMURI_RAP_HEADER_H

#include <array>

#include "date.h"

struct RapDescriptor {
    std::array<unsigned char, 8> packId;
    std::array<unsigned char, 4> packVersion;
    Date packDate;
    uint8_t packProducerId;
};

struct RapStructureDescriptor {
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
    uint8_t targetPlatformId;
    uint8_t reconfigurationClass;
};

struct RapHeader {
    RapDescriptor packDescriptor;
    RapStructureDescriptor packStructureDescriptor;
    RadioLibDescriptor radioLibDescriptor;
    TargetPlatformDescriptor targetPlatformDescriptor;
};

#endif //IMURI_RAP_HEADER_H