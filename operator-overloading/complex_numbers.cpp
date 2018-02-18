//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#include "Complex.h"

using namespace cave;

void intro_to_complex() {
    Complex c1(2, 3);
    Complex c2(c1);
    Complex c3;
    c3 = c2;

    cout << c2  << " " << c3 << endl;
}

void overloading_plus() {
    Complex c1(3, 4);
    Complex c2(2, 3);
    Complex c3 = c1+c2;
    cout << c1 << endl;
    cout << c1+c2+c3 << endl;

    Complex c4(4, 2);
    Complex c5 = c4+7;
    cout << c5 << endl;

    Complex c6(1, 7);
    cout << 3.2 + c6 << endl;
    cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;
}

void overloading_comparison() {
    Complex c1(3, 2);
    Complex c2(3, 1);
    if(c1 == c2) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    if(c1 != c2) {
        cout << "Not Equal" << endl;
    } else {
        cout << "Equal" << endl;
    }
}

void overloading_dereference() {
    Complex c1(2, 4);
    cout << *c1 + *Complex(4, 3) << endl;
    cout << Complex(3, 4)*Complex(3, 4) << endl;
}

int main() {
    overloading_dereference();
    return 0;
}
