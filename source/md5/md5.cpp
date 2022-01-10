#include <cmath>

#include "md5.h"

unsigned char *Md5::appendedData{nullptr};
uint32_t Md5::sizeAfterAppendingInBytes{0};
uint32_t Md5::incomingDataSizeInBytes{0};

uint32_t Md5::A{0};
uint32_t Md5::B{0};
uint32_t Md5::C{0};
uint32_t Md5::D{0};

std::array<uint32_t, 64> Md5::T;
bool Md5::isNeedInitializeT{true};

std::string Md5::getMd5Hash(const std::string &data) {
    incomingDataSizeInBytes = static_cast<uint32_t>(data.size());
    calculateSizeForAppending();
    appendedData = new unsigned char[sizeAfterAppendingInBytes];

    appendIncomingData(data);
    appendPaddingBits();
    appendLength();
    initializeMdBuffer();
    processMessage();

    delete[]appendedData;
    appendedData = nullptr;

    return getOutputHash();
}

void Md5::calculateSizeForAppending() {
    uint32_t rest{incomingDataSizeInBytes % 64};

    if (rest < 56)
        sizeAfterAppendingInBytes = incomingDataSizeInBytes - rest + 56 + 8;
    else
        sizeAfterAppendingInBytes = incomingDataSizeInBytes + 64 - rest + 56 + 8;
}

void Md5::appendIncomingData(const std::string &incomingData) {
    for (size_t i = 0; i < incomingDataSizeInBytes; i++) {
        appendedData[i] = static_cast<unsigned char>(incomingData.at(i));
    }
}

void Md5::appendPaddingBits() {
    appendedData[incomingDataSizeInBytes] = 0x80;

    for (uint32_t i = incomingDataSizeInBytes + 1; i < sizeAfterAppendingInBytes; i++) {
        appendedData[i] = 0;
    }
}

void Md5::appendLength() {
    uint64_t incomingDataBitsSize = incomingDataSizeInBytes * 8;

    for (size_t i = 0; i < 8; i++) {
        appendedData[sizeAfterAppendingInBytes - 8 + i] = static_cast<unsigned char>(incomingDataBitsSize >> i * 8);
    }
}

void Md5::initializeMdBuffer() {
    A = 0x67452301;
    B = 0xEFCDAB89;
    C = 0x98BADCFE;
    D = 0x10325476;
}

void Md5::processMessage() {
    initializeT();
    uint32_t AA, BB, CC, DD;
    auto *X = (uint32_t *) (appendedData);

    for (size_t i = 0; i < sizeAfterAppendingInBytes / 4; i += 16) {
        AA = A;
        BB = B;
        CC = C;
        DD = D;

        runStage1(i, X);
        runStage2(i, X);
        runStage3(i, X);
        runStage4(i, X);

        A += AA;
        B += BB;
        C += CC;
        D += DD;
    }
}

void Md5::initializeT() {
    if (isNeedInitializeT) {
        isNeedInitializeT = false;

        for (size_t i = 0; i < 64; i++)
            T.at(i) = static_cast<uint32_t>(pow(2.0, 32.0) * fabs(sin(static_cast<double>(i + 1))));
    }
}

void Md5::runStage1(size_t i, const uint32_t *X) {
    A = B + rotateLeft((A + calculateF(B, C, D) + X[i + 0] + T.at(0)), 7);
    D = A + rotateLeft((D + calculateF(A, B, C) + X[i + 1] + T.at(1)), 12);
    C = D + rotateLeft((C + calculateF(D, A, B) + X[i + 2] + T.at(2)), 17);
    B = C + rotateLeft((B + calculateF(C, D, A) + X[i + 3] + T.at(3)), 22);

    A = B + rotateLeft((A + calculateF(B, C, D) + X[i + 4] + T.at(4)), 7);
    D = A + rotateLeft((D + calculateF(A, B, C) + X[i + 5] + T.at(5)), 12);
    C = D + rotateLeft((C + calculateF(D, A, B) + X[i + 6] + T.at(6)), 17);
    B = C + rotateLeft((B + calculateF(C, D, A) + X[i + 7] + T.at(7)), 22);

    A = B + rotateLeft((A + calculateF(B, C, D) + X[i + 8] + T.at(8)), 7);
    D = A + rotateLeft((D + calculateF(A, B, C) + X[i + 9] + T.at(9)), 12);
    C = D + rotateLeft((C + calculateF(D, A, B) + X[i + 10] + T.at(10)), 17);
    B = C + rotateLeft((B + calculateF(C, D, A) + X[i + 11] + T.at(11)), 22);

    A = B + rotateLeft((A + calculateF(B, C, D) + X[i + 12] + T.at(12)), 7);
    D = A + rotateLeft((D + calculateF(A, B, C) + X[i + 13] + T.at(13)), 12);
    C = D + rotateLeft((C + calculateF(D, A, B) + X[i + 14] + T.at(14)), 17);
    B = C + rotateLeft((B + calculateF(C, D, A) + X[i + 15] + T.at(15)), 22);
}

void Md5::runStage2(size_t i, const uint32_t *X) {
    A = B + rotateLeft((A + calculateG(B, C, D) + X[i + 1] + T.at(16)), 5);
    D = A + rotateLeft((D + calculateG(A, B, C) + X[i + 6] + T.at(17)), 9);
    C = D + rotateLeft((C + calculateG(D, A, B) + X[i + 11] + T.at(18)), 14);
    B = C + rotateLeft((B + calculateG(C, D, A) + X[i + 0] + T.at(19)), 20);

    A = B + rotateLeft((A + calculateG(B, C, D) + X[i + 5] + T.at(20)), 5);
    D = A + rotateLeft((D + calculateG(A, B, C) + X[i + 10] + T.at(21)), 9);
    C = D + rotateLeft((C + calculateG(D, A, B) + X[i + 15] + T.at(22)), 14);
    B = C + rotateLeft((B + calculateG(C, D, A) + X[i + 4] + T.at(23)), 20);

    A = B + rotateLeft((A + calculateG(B, C, D) + X[i + 9] + T.at(24)), 5);
    D = A + rotateLeft((D + calculateG(A, B, C) + X[i + 14] + T.at(25)), 9);
    C = D + rotateLeft((C + calculateG(D, A, B) + X[i + 3] + T.at(26)), 14);
    B = C + rotateLeft((B + calculateG(C, D, A) + X[i + 8] + T.at(27)), 20);

    A = B + rotateLeft((A + calculateG(B, C, D) + X[i + 13] + T.at(28)), 5);
    D = A + rotateLeft((D + calculateG(A, B, C) + X[i + 2] + T.at(29)), 9);
    C = D + rotateLeft((C + calculateG(D, A, B) + X[i + 7] + T.at(30)), 14);
    B = C + rotateLeft((B + calculateG(C, D, A) + X[i + 12] + T.at(31)), 20);
}

void Md5::runStage3(size_t i, const uint32_t *X) {
    A = B + rotateLeft((A + calculateH(B, C, D) + X[i + 5] + T.at(32)), 4);
    D = A + rotateLeft((D + calculateH(A, B, C) + X[i + 8] + T.at(33)), 11);
    C = D + rotateLeft((C + calculateH(D, A, B) + X[i + 11] + T.at(34)), 16);
    B = C + rotateLeft((B + calculateH(C, D, A) + X[i + 14] + T.at(35)), 23);

    A = B + rotateLeft((A + calculateH(B, C, D) + X[i + 1] + T.at(36)), 4);
    D = A + rotateLeft((D + calculateH(A, B, C) + X[i + 4] + T.at(37)), 11);
    C = D + rotateLeft((C + calculateH(D, A, B) + X[i + 7] + T.at(38)), 16);
    B = C + rotateLeft((B + calculateH(C, D, A) + X[i + 10] + T.at(39)), 23);

    A = B + rotateLeft((A + calculateH(B, C, D) + X[i + 13] + T.at(40)), 4);
    D = A + rotateLeft((D + calculateH(A, B, C) + X[i + 0] + T.at(41)), 11);
    C = D + rotateLeft((C + calculateH(D, A, B) + X[i + 3] + T.at(42)), 16);
    B = C + rotateLeft((B + calculateH(C, D, A) + X[i + 6] + T.at(43)), 23);

    A = B + rotateLeft((A + calculateH(B, C, D) + X[i + 9] + T.at(44)), 4);
    D = A + rotateLeft((D + calculateH(A, B, C) + X[i + 12] + T.at(45)), 11);
    C = D + rotateLeft((C + calculateH(D, A, B) + X[i + 15] + T.at(46)), 16);
    B = C + rotateLeft((B + calculateH(C, D, A) + X[i + 2] + T.at(47)), 23);
}

void Md5::runStage4(size_t i, const uint32_t *X) {
    A = B + rotateLeft((A + calculateI(B, C, D) + X[i + 0] + T.at(48)), 6);
    D = A + rotateLeft((D + calculateI(A, B, C) + X[i + 7] + T.at(49)), 10);
    C = D + rotateLeft((C + calculateI(D, A, B) + X[i + 14] + T.at(50)), 15);
    B = C + rotateLeft((B + calculateI(C, D, A) + X[i + 5] + T.at(51)), 21);

    A = B + rotateLeft((A + calculateI(B, C, D) + X[i + 12] + T.at(52)), 6);
    D = A + rotateLeft((D + calculateI(A, B, C) + X[i + 3] + T.at(53)), 10);
    C = D + rotateLeft((C + calculateI(D, A, B) + X[i + 10] + T.at(54)), 15);
    B = C + rotateLeft((B + calculateI(C, D, A) + X[i + 1] + T.at(55)), 21);

    A = B + rotateLeft((A + calculateI(B, C, D) + X[i + 8] + T.at(56)), 6);
    D = A + rotateLeft((D + calculateI(A, B, C) + X[i + 15] + T.at(57)), 10);
    C = D + rotateLeft((C + calculateI(D, A, B) + X[i + 6] + T.at(58)), 15);
    B = C + rotateLeft((B + calculateI(C, D, A) + X[i + 13] + T.at(59)), 21);

    A = B + rotateLeft((A + calculateI(B, C, D) + X[i + 4] + T.at(60)), 6);
    D = A + rotateLeft((D + calculateI(A, B, C) + X[i + 11] + T.at(61)), 10);
    C = D + rotateLeft((C + calculateI(D, A, B) + X[i + 2] + T.at(62)), 15);
    B = C + rotateLeft((B + calculateI(C, D, A) + X[i + 9] + T.at(63)), 21);
}

uint32_t Md5::rotateLeft(uint32_t value, uint32_t shift) {
    return value << shift | value >> (32 - shift);
}

uint32_t Md5::calculateF(uint32_t X, uint32_t Y, uint32_t Z) {
    return ((X & Y) | ((~X) & Z));
}

uint32_t Md5::calculateG(uint32_t X, uint32_t Y, uint32_t Z) {
    return (X & Z) | (Y & (~Z));
}

uint32_t Md5::calculateH(uint32_t X, uint32_t Y, uint32_t Z) {
    return X ^ Y ^ Z;
}

uint32_t Md5::calculateI(uint32_t X, uint32_t Y, uint32_t Z) {
    return Y ^ (X | (~Z));
}

std::string Md5::getOutputHash() {
    return toHexAsString(A) + toHexAsString(B) + toHexAsString(C) + toHexAsString(D);
}

std::string Md5::toHexAsString(uint32_t value) {
    std::string resultWord;
    unsigned char hex;
    char hexResult[3];

    while (value) {
        hex = value % 256;
        sprintf(hexResult, "%x", hex);

        if (hexResult[1] == '\0') {
            hexResult[1] = hexResult[0];
            hexResult[0] = '0';
            hexResult[2] = '\0';
        }

        resultWord.append(hexResult);
        value /= 256;
    }

    return resultWord;
}