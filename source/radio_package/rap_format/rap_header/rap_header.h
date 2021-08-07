//
// Created by apt-15 on 07.08.2021.
//

#ifndef IMURI_RAP_HEADER_H
#define IMURI_RAP_HEADER_H

#include "rap_descriptor.h"
#include "rap_structure_descriptor.h"
#include "radio_lib_descriptor.h"
#include "target_platform_descriptor.h"

struct RapHeader {
    RapDescriptor rapDescriptor;
    RapStructureDescriptor rapStructureDescriptor;
    RadioLibDescriptor radioLibDescriptor;
    TargetPlatformDescriptor targetPlatformDescriptor;
};

#endif //IMURI_RAP_HEADER_H
