#ifndef IMURI_MD5_H
#define IMURI_MD5_H

#include <array>
#include <cstdint>
#include <string>
#include <vector>

class Md5 {
private:
    static unsigned char *appendedData;
    static uint32_t sizeAfterAppendingInBytes;
    static uint32_t incomingDataSizeInBytes;

    static uint32_t A;
    static uint32_t B;
    static uint32_t C;
    static uint32_t D;

    static std::array<uint32_t, 64> T;
    static bool isNeedInitializeT;

public:
    Md5() = delete;

    ~Md5() = delete;

    static std::string getMd5Hash(const std::string &data);

private:
    static void calculateSizeForAppending();

    static void appendIncomingData(const std::string &incomingData);

    static void appendPaddingBits();

    static void appendLength();

    static void initializeMdBuffer();

    static void processMessage();

    static void initializeT();

    static void runStage1(size_t i, const uint32_t *X);

    static void runStage2(size_t i, const uint32_t *X);

    static void runStage3(size_t i, const uint32_t *X);

    static void runStage4(size_t i, const uint32_t *X);

    static uint32_t rotateLeft(uint32_t value, uint32_t shift);

    static uint32_t calculateF(uint32_t X, uint32_t Y, uint32_t Z);

    static uint32_t calculateG(uint32_t X, uint32_t Y, uint32_t Z);

    static uint32_t calculateH(uint32_t X, uint32_t Y, uint32_t Z);

    static uint32_t calculateI(uint32_t X, uint32_t Y, uint32_t Z);

    static std::string getOutputHash();

    static std::string toHexAsString(uint32_t value);
};

#endif //IMURI_MD5_H