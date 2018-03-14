//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#include "ZoomList.h"

namespace blackbox {
    ZoomList::ZoomList(int width, int height): _width(width), _height(height) {

    }

    void ZoomList::add(const Zoom &zoom) {
        _zooms.push_back(zoom);

        _xCenter += (zoom.x - (_width / 2)) * _scale;
        _yCenter += -(zoom.y - (_height / 2)) * _scale;

        _scale *= zoom.scale;
    }

    pair<double, double> ZoomList::doZoom(int x, int y) {
        double xFractal = (x - _width/2) * _scale + _xCenter;
        double yFractal = (y - _height/2) * _scale + _yCenter;
        return { xFractal, yFractal };
    }
}
