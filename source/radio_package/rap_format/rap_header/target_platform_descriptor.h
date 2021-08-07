//
// Created by apt-15 on 07.08.2021.
//

#ifndef IMURI_TARGET_PLATFORM_DESCRIPTOR_H
#define IMURI_TARGET_PLATFORM_DESCRIPTOR_H

#include <cstdint>

struct TargetPlatformDescriptor {
    char targetPlatformId[8];
    uint64_t mobileDeviceOrRadioEquipmentReconfiguration;
};

#endif //IMURI_TARGET_PLATFORM_DESCRIPTOR_H
