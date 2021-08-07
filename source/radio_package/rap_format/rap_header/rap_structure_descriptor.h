//
// Created by apt-15 on 07.08.2021.
//

#ifndef IMURI_RAP_STRUCTURE_DESCRIPTOR_H
#define IMURI_RAP_STRUCTURE_DESCRIPTOR_H

#include <cstdint>

struct RapStructureDescriptor {
    uint64_t uraCodeBias;
    uint64_t securityBias;
    uint64_t manufacturerInfoBias;
    uint64_t initialProfileBias;
    uint64_t reserveBias;
};

#endif //IMURI_RAP_STRUCTURE_DESCRIPTOR_H
