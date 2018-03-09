//
// Created by Shidfar Hodizoda on 03/03/2018.
//

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void run() = 0;
    virtual void speak() = 0;
};

class Dog: public Animal {
public:
    void speak() override {
        cout << "Woof" << endl;
    }
};

class Labrador: public Dog {
public:
    Labrador() {
        cout << "new labrador" << endl;
    }
    void run() override {
        cout << "Labrador running" << endl;
    }
};

void test(Animal &a) {
    a.speak();
}

int main() {
//    Dog dog;
//    dog.speak();
//  --- ---  --- ---
    Labrador lab;
    lab.speak();
    lab.run();

//    Animal animals[2];
    Labrador labs[5];
    Animal *animals[5];
    animals[0] = &lab;

    animals[0]->speak();

    test(lab);

    return 0;
}
