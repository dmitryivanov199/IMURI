//
// Created by apt-15 on 07.08.2021.
//

#ifndef IMURI_RAP_DESCRIPTOR_H
#define IMURI_RAP_DESCRIPTOR_H

#include "../date/date.h"

struct RapDescriptor {
    char rapId[8];
    char rapVersion[8];
    Date rapDate;
    char rapProducerId[8];
};

#endif //IMURI_RAP_DESCRIPTOR_H
