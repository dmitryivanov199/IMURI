//
// Created by apt-15 on 07.08.2021.
//

#ifndef IMURI_RADIO_LIB_DESCRIPTOR_H
#define IMURI_RADIO_LIB_DESCRIPTOR_H

#include "../date/date.h"

struct RadioLibDescriptor {
    char radioLibVersion[8];
    Date radioLibDate;
};

#endif //IMURI_RADIO_LIB_DESCRIPTOR_H
