//
// Created by Shidfar Hodizoda on 14/03/2018.
//

#ifndef C_11_RGB_H
#define C_11_RGB_H

namespace blackbox {
    struct RGB {
        double r;
        double g;
        double b;

        RGB(double r, double g, double b);
    };

    RGB operator-(const RGB& first, const RGB& second);
}

#endif //C_11_RGB_H
