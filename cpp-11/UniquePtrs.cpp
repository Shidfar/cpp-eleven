//
// Created by Shidfar Hodizoda on 11/03/2018.
//

#include "Cpp11.h"

class UPTest {
public:
    UPTest() {
        cout << "created" << endl;
    }
    void greet() {
        cout << "Hello" << endl;
    }

    ~UPTest() {
        cout << "destroyed" << endl;
    }
};

class Temp {
private:
    unique_ptr<UPTest[]> up_test;
public:
    Temp(): up_test(new UPTest[2]) {

    }
};

void Cpp11::unique_ptrs() {
    unique_ptr<int> p_test(new int);

    *p_test = 7;
    cout << *p_test << endl;

    {
        unique_ptr<UPTest[]> up_test(new UPTest[2]);
//        auto_ptr<UPTest> up_test(new UPTest);  // <- deprecated
        up_test[1].greet();
    }
    cout << "out of scope" << endl;

    Temp temp;

    cout << "finished" << endl;
}
