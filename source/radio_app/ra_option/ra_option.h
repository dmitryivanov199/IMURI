#ifndef IMURI_RA_OPTION_H
#define IMURI_RA_OPTION_H

enum class RAOptionID {
    lte5Mhz,
    lte10Mhz,
    lte20Mhz,
    lte50Mhz,
    lte100Mhz
};

template<class T>
class RAOption {
private:
    RAOptionID rAOptionName;
    T rAOptionValue;

public:
    RAOption(const RAOptionID &optionName, const T &optionValue) :
            rAOptionName{optionName},
            rAOptionValue{optionValue} {
    }

    ~RAOption() = default;
};

#endif //IMURI_RA_OPTION_H