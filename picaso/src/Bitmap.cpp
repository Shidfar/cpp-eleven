//
// Created by Shidfar Hodizoda on 12/03/2018.
//

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

#include <fstream>

namespace blackbox {
    Bitmap::Bitmap(int width, int height): _width(width), _height(height),
                                           _pPixels(new uint8_t[_width * _height * 3]{}) {
//        memset(_pPixels.get(), 0, sizeof(uint8_t) * _width * _height * 3);
    }

    bool Bitmap::write(string &filename) {
        BitmapInfoHeader infoHeader;
        BitmapFileHeader fileHeader;

        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (_width * _height * 3);
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

        infoHeader.width = _width;
        infoHeader.height = _height;

        ofstream file;
        file.open(filename.c_str(), ios::out|ios::binary);

        if(!file) {
            return false;
        }

        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)_pPixels.get(), _width * _height * 3);

        file.close();
        return ~(!file);

    }

    void Bitmap::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
        uint8_t *pPixel = _pPixels.get();

        pPixel += ((y * 3) * _width) + (x * 3);

        pPixel[0] = b;
        pPixel[1] = g;
        pPixel[2] = r;
    }

    Bitmap::~Bitmap() {
//        delete[] _pPixels;
    }
}
