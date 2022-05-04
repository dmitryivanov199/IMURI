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

    enum class Uninstallation {
        OK,
        NO_URA,
        ACTIVATED
    };

    enum class Instantiation {
        OK,
        NO_URA,
        ACTIVATED,
        ALREADY_INSTANTIATED
    };

    enum class Deletion {
        OK,
        NO_URA,
        ACTIVATED,
        ALREADY_DELETED
    };

    enum class Activation {
        OK,
        NO_URA,
        ALREADY_ACTIVATED,
        NOT_INSTANTIATED
    };
}

#endif //IMURI_ERROR_CODES_H