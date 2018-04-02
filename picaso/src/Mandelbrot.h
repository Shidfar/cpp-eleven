//
// Created by Shidfar Hodizoda on 13/03/2018.
//

#ifndef PICASO_MANDELBROT_H
#define PICASO_MANDELBROT_H

namespace blackbox {
    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 100000;

    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);
    };
}


#endif //PICASO_MANDELBROT_H
