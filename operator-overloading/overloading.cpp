//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;

public:
    Test(): id(0), name("") {
    }

    Test(int id, string name):
            id(static_cast<typename  remove_reference<int>::type &&>(id)),
            name(static_cast<typename remove_reference<string>::type &&>(name)) {
    }

    void print() {
        cout << id << ": " << name << endl;
    }

    const Test& operator=(const Test& other) {
        cout << "Assignment is running" << endl;

        id = other.id;
        name = other.name;

        return *this;
    }

    Test(const Test &other) {
        cout << "Copy constructor is running" << endl;
        id = other.id;
        name = other.name;
        /// OR:
//        *this = other;
    }

    string get_name() const {
        return name;
    }

    int get_id() const {
        return id;
    }

    friend ostream& operator<<(ostream& out, const Test& test) {
        out << test.id <<": " << test.name;
        return out;
    }
};

/*
// fulling around

ostream& operator<<(ostream& out, const Test& test) {
    out << test.get_id() <<": " << test.get_name();
    return out;
}

ostream& operator<<(ostream& out, const string& str) {
    out << " > " << str.c_str();
    return out;
}
*/

void assignment_overloading() {
    Test test1(10, "Mike");
    cout << "Print test1 " << flush;
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;
    cout << "Print test2 " << flush;
    test2.print();

    Test test3;
//    test3 = test2 = test1;

    test3.operator=(test2); // -> test3 = test2;
    cout << "Print test3 " << flush;
    test3.print();

    cout << endl;
    // Copy initialization
    Test test4 = test1;
    test4.print();
}

void binary_shift_overloading() {
    Test test1(10, "Mike");
    Test test2(20, "Bob");
//    test1.print();

    cout << test1 << endl << test2 << endl;
//    cout << string("Hello") << endl;
}

template <class T>
ostream& operator>>(ostream& out, T &v) {
    cout << " -- ";
    out << v;
    return out;
}

ostream& operator>>(ostream& out, const bool &v) {
    out << (v ? "True" : "False");
    return out;
}

int main() {
//    binary_shift_overloading();
    std::cout << "string " >> double(12.23) >> bool(true) << endl;

    return 0;
}

/*
 * The Rule of three:
 *  if you define a "Copy constructor", or an "Assignment operator",
 *  or a "Destructor" you should implement the other two as well.
 * */
