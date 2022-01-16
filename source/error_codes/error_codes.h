#ifndef IMURI_ERROR_CODES_H
#define IMURI_ERROR_CODES_H

namespace Codes {
    enum class Installation {
        OK,
        NO_RAP,
        NO_URA,
        ALREADY_INSTALLED,
        BAD_FILE
    };
}

#endif //IMURI_ERROR_CODES_H