#include <iostream>
#ifndef CRC_H
#define CRC_H

uint32_t calculateCRC32(const uint8_t* data, size_t length) {

    constexpr uint32_t CRC32_POLYNOMIAL = 0xEDB88320;

    uint32_t crc = 0xFFFFFFFF; // Initial CRC value
    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ ((crc & 1) ? CRC32_POLYNOMIAL : 0);
        }
    }
    return ~crc; // Final CRC value
}

uint32_t calculateCRC32(const char* str) {
    return calculateCRC32(reinterpret_cast<const uint8_t*>(str), strlen(str));
}

#endif // !CRC_H
