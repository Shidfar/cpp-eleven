//
// Created by Shidfar Hodizoda on 01/03/2018.
//

#include <iostream>
using namespace std;

class Parent {
private:
    int one;
public:
    Parent(): one(0) {
        cout << "construct parent" << endl;
    }

    Parent(const Parent &other) {
        one = other.one;
        cout << "copy parent" << endl;
    }

    virtual void print() {
        cout << "parent" << endl;
    }
    virtual ~Parent() {

    }
//    void print() {                   // if function is not virtual
//        cout << "parent" << endl;    // it won't be overridden
//    }
};

class Child: public Parent {
private:
    int two;
public:
    Child(): two(0) {

    }

    void print() override {
        cout << "child" << endl;
    }
};

int main() {
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();


    Parent *p3 = new Child();
    p3->print();

    return 0;
}
