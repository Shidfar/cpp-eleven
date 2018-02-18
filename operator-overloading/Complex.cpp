//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#include "Complex.h"

namespace cave {

    ostream& operator<<(ostream& out, const Complex& obj) {
        out << "(" << obj.get_real() << "," << obj.get_imaginary() << ")";
        return out;
    }

    Complex operator+(const Complex &c1, const Complex &c2) {
        return Complex(c1.get_real()+c2.get_real(),
                       c1.get_imaginary()+c2.get_imaginary());
    }

    Complex operator+(const Complex &c1, double d) {
        return Complex(c1.get_real()+d, c1.get_imaginary());
    }


    Complex operator+(double d, const Complex &c1) {
        return Complex(c1.get_real()+d, c1.get_imaginary());
    }

    bool Complex::operator==(const Complex &other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool Complex::operator!=(const Complex &other) const {
        return !(*this == other);
    }

    Complex Complex::operator*() const {
        return Complex(real, -imaginary);
    }

    Complex operator*(const Complex &c1, const Complex &c2) {
        return Complex(c1.get_real()*c2.get_real(),
                       c1.get_imaginary()*c2.get_imaginary());
    }

    Complex::Complex(): real(0), imaginary(0) {

    }

    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {

    }

    Complex::Complex(const Complex& other)  {
//            *this = other;
        // or
        real = other.real;
        imaginary = other.imaginary;
    }

    const Complex &Complex::operator=(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }
}