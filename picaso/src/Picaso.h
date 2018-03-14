//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#ifndef C_11_PICASO_H
#define C_11_PICASO_H

#include <string>
#include <cmath>
#include <cstdint>
#include <memory>
#include <cassert>

#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace blackbox {
    class Picaso {
    private:
        int _width;
        int _height;
        unique_ptr<int[]> _histogram;
        unique_ptr<int[]> _fractal;
        Bitmap _bitmap;
        ZoomList _zoomList;
        int _total{0};

        vector<int> _ranges;
        vector<RGB> _colors;
        vector<int> _rangeTotals;

        bool _bGotFirstRange{false};

    public:
        Picaso(int width, int height);
        void run(string filename);
        void addRange(double rangeEnd, const RGB& rgb);
        void addZoom(const Zoom& zoom);
        virtual ~Picaso();

    private:
        void calculateIteration();
        void calculateRangeTotals();
        void calculateTotalIterations();
        void drawFractal();
        void writeBitmap(string filename);
        int getRange(int iterations) const;
    };
}


#endif //C_11_PICASO_H
