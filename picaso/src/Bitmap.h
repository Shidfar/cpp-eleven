//
// Created by Shidfar Hodizoda on 12/03/2018.
//

#ifndef PICASO_BITMAP_H
#define PICASO_BITMAP_H

#include <string>
#include <cstdint>

using namespace std;
namespace blackbox {
    class Bitmap {
    private:
        int _width{0};
        int _height{0};
        unique_ptr<uint8_t[]> _pPixels{nullptr};
//        uint8_t *_pPixels[]{NULL};

    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
        bool write(string filename);
        virtual ~Bitmap();
    };
}

#endif //PICASO_BITMAP_H
