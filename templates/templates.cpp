//
// Created by Shidfar Hodizoda on 19/02/2018.
//
#include <iostream>

using namespace std;

template <class T, class K>
class Test {
private:
    T obj;
public:
    Test(T obj) {
        this->obj = obj;
    }
    void print() {
        cout << obj << endl;
    }
};

template <class T>
void print(T n) {
    cout << "Template version: " << n << endl;
}

void print(int n) {
    cout << "Non-template version: " << n << endl;
}

template <class T>
void show() {
    cout << T() << endl;
}

int main() {
    Test<string, int> test1("Hello");
    test1.print();

    print<string>("Hello");
    print<int>(5);

    print("Hi there");

    print(5);
    print<>(6);

    show<double >();

    return 0;
}
