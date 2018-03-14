//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#ifndef C_11_ZOOM_H
#define C_11_ZOOM_H

#include <iostream>

using namespace std;

namespace blackbox {
    struct Zoom {
        int x{0};
        int y{0};
        double scale{0.0};
        Zoom *node{nullptr};

        Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {
        }
    };
}

#endif //C_11_ZOOM_H
