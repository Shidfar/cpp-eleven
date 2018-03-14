//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#ifndef C_11_ZOOMLIST_H
#define C_11_ZOOMLIST_H

#include <vector>
#include <utility>

#include "Zoom.h"

namespace blackbox {
    class ZoomList {
    private:
        double _xCenter{0.0};
        double _yCenter{0.0};
        double _scale{1.0};

        int _width{0};
        int _height{0};
        vector<Zoom> _zooms;

    public:
        ZoomList(int width, int height);
        void add(const Zoom &zoom);
        pair<double, double> doZoom(int x, int y);
    };
}

#endif //C_11_ZOOMLIST_H
