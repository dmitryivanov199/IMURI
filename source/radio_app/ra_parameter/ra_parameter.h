#ifndef IMURI_RA_PARAMETER_H
#define IMURI_RA_PARAMETER_H

enum class RadioAppParameterID {
    A,
    B,
    C,
    D,
    E
};

template<class T>
class RadioAppParameter {
private:
    RadioAppParameterID radioAppParameterName;
    T radioAppParameterValue;

public:
    RadioAppParameter(const RadioAppParameterID &parameterId, const T &parameterValue) :
            radioAppParameterName(parameterId),
            radioAppParameterValue(parameterValue) {
    }

    ~RadioAppParameter() = default;
};

#endif //IMURI_RA_PARAMETER_H