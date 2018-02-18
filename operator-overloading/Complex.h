//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#ifndef C_11_COMPLEX_H
#define C_11_COMPLEX_H

#include <iostream>
using namespace std;

namespace cave {
    class Complex {
    private:
        double real;
        double imaginary;

    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex& other);
        const Complex &operator=(const Complex &other);

        double get_real() const { return real; }
        double get_imaginary() const { return imaginary; }

        bool operator==(const Complex &other) const;
        bool operator!=(const Complex &other) const;
        Complex operator*() const;
    };

    ostream& operator<<(ostream& out, const Complex& obj);
    Complex operator+(const Complex &c1, const Complex &c2);
    Complex operator*(const Complex &c1, const Complex &c2);
    Complex operator+(const Complex &c1, double d);
    Complex operator+(double d, const Complex &c1);
}

#endif //C_11_COMPLEX_H
