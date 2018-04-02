//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#include "Picaso.h"

namespace blackbox {
    Picaso::Picaso(int width, int height): _width(width), _height(height),
                                           _histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
                                           _fractal(new int[_width * _height]{0}),
                                           _bitmap(_width, _height),
                                           _zoomList(_width, _height) {
        _zoomList.add(Zoom((_width/2), _height/2, 4.0/_width));
    }

    void Picaso::run(string &filename) {
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(filename);
    }

    void Picaso::addRange(double rangeEnd, const RGB &rgb) {
        _ranges.push_back((int) rangeEnd * Mandelbrot::MAX_ITERATIONS);
        _colors.push_back(rgb);

        if(_bGotFirstRange) {
            _rangeTotals.push_back(0);
        }
        _bGotFirstRange = true;
    }

    void Picaso::addZoom(const Zoom &zoom) {
        _zoomList.add(zoom);
    }

    void Picaso::calculateIteration() {
        for(int y = 0; y < _height; y++) {
            for(int x = 0; x < _width; x++) {
                pair<double, double> coords = _zoomList.doZoom(x, y);

                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                _fractal[(y * _width) + x] = iterations;

                if(iterations != Mandelbrot::MAX_ITERATIONS) {
                    _histogram[iterations]++;
                }
            }
        }
    }

    void Picaso::calculateRangeTotals() {
        int rangeIndex = 0;

        for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
            int pixels = _histogram[i];
            if(i >= _ranges[rangeIndex+1]) {
                rangeIndex++;
            }
            _rangeTotals[rangeIndex] += pixels;
        }
    }

    void Picaso::calculateTotalIterations() {
        for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
            _total += _histogram[i];
        }
    }

    void Picaso::drawFractal() {
        for(int y = 0; y < _height; y++) {
            for(int x = 0; x < _width; x++) {
                int iterations = _fractal[y * _width + x];

                int range = getRange(iterations);
                int rangeTotal = _rangeTotals[range];
                int rangeStart = _ranges[range];

                RGB& startColor = _colors[range];
                RGB& endColor = _colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t r = 0;
                uint8_t g = 0;
                uint8_t b = 0;

                if(iterations != Mandelbrot::MAX_ITERATIONS) {
                    int totalPixels =  0;
                    for(int i = rangeStart; i <= iterations; i++) {
                        totalPixels += _histogram[i];
                    }
                    r = static_cast<uint8_t>(startColor.r
                                             + colorDiff.r
                                               * (double) totalPixels / rangeTotal);
                    g = static_cast<uint8_t>(startColor.g
                                             + colorDiff.g
                                               * (double) totalPixels / rangeTotal);
                    b = static_cast<uint8_t>(startColor.b
                                             + colorDiff.b
                                               * (double) totalPixels / rangeTotal);
                }
                _bitmap.setPixel(x, y, r, g, b);
            }
        }
    }

    void Picaso::writeBitmap(string &filename) {
        _bitmap.write(filename);
    }

    Picaso::~Picaso() {
    }

    int Picaso::getRange(int iterations) const {
        int range = 0;
        for(int i=1; i<_ranges.size(); i++) {
            range = i;
            if(_ranges[i] > iterations) {
                break;
            }
        }
        range --;
        assert(range > -1);
        assert(range < _ranges.size());

        return range;
    }
}