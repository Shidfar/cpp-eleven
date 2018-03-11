//
// Created by Shidfar Hodizoda on 11/03/2018.
//

#include "Cpp11.h"

using namespace placeholders;

class BindTest {
public:
    int add(int a, int b, int c) {
        cout << a << ", " << b <<", " << c << endl;
        return a + b + c;
    }
};

//int add(int a, int b, int c) {
//    cout << a << ", " << b <<", " << c << endl;
//    return a + b + c;
//}

int run(function<int(int, int)> func) {
    return func(7, 3);
}

void Cpp11::binding() {
//    cout << add(1, 2, 3) << endl;
    BindTest test;
    auto calculate = bind(&BindTest::add, test, _2, 100, _1);
//    cout << calculate(10, 20) << endl;
    cout << run(calculate) << endl;
}
