//
// Created by Shidfar Hodizoda on 12/03/2018.
//

#ifndef PICASO_BITMAPFILEHEADER_H
#define PICASO_BITMAPFILEHEADER_H

#include <iostream>
#include <cstdio>
#include <cstdint>

#pragma pack(2)
namespace blackbox {
    struct BitmapFileHeader {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };
}


#endif //PICASO_BITMAPFILEHEADER_H
