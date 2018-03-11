//
// Created by Shidfar Hodizoda on 11/03/2018.
//

#include <iostream>
#include <vector>

using namespace std;

class ElOpTest {
public:
    ElOpTest() {
        cout << "constructor" << endl;
    }
    ElOpTest(int i) {
        cout << "parameter constructor" << endl;
    }
    ElOpTest(const ElOpTest& other) {
        cout << "copy constructor" << endl;
    }
    ElOpTest&operator=(const ElOpTest&) {
        cout << "assignment operator" << endl;
        return *this;
    }
    ~ElOpTest() {
        cout << "destructor" << endl;
    }
    friend ostream& operator<<(ostream& out, const ElOpTest& obj);
};

ostream &operator<<(ostream &out, const ElOpTest& obj) {
    cout << "hello from test";
    return out;
}

ElOpTest getElOpTest() {
    return ElOpTest();
}

void elision_n_optimization() {
    ElOpTest test1 = getElOpTest();
    vector<ElOpTest> vec;

    vec.push_back(ElOpTest());
    cout << test1 << endl;
}

int main() {
    elision_n_optimization();
    return 0;
}

// c++ -std=c++98 -fno-elide-constructors cpp98-elision.cpp -o cpp98
//                ^^^^^^^^^^^^^^^^^^^^^^^
// GCC provides the ‑fno‑elide‑constructors option to disable copy-elision.
