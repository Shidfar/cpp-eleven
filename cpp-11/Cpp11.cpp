//
// Created by Shidfar Hodizoda on 04/03/2018.
//

#include "Cpp11.h"

class InitListTest {
public:
    InitListTest(initializer_list<string> texts) {
        for(const auto &value: texts) {
            cout << value << endl;
        }
    }
    void print(initializer_list<string> texts) {
        for(const auto &value: texts) {
            cout << value << endl;
        }
    }
};

class ObjInitTest {
    int id{3};
    string name{"Mike"};
public:
    ObjInitTest() = default;
    ObjInitTest(const ObjInitTest &other) = default; // | delete; // deleting the implicit constructor | using default
    ObjInitTest &operator=(const ObjInitTest &other) = default;

    explicit ObjInitTest(int _id): id(_id) {

    }
    void print() {
        cout << id << ": " << name << endl;
    }
};

void Cpp11::nested_templates() {
//    ring<int>::iterator p;
//    p.print();
//    p.inform();
//    ring<double>::terminator a;
//    a.warn();

    ring<string>text_ring(3);
    text_ring.add("one");
    text_ring.add("two");
    text_ring.add("three");
    text_ring.add("four");

//    for(int i=0; i<text_ring.size(); i++) {
//        cout << text_ring.get(i) << endl;
//    }

    for(ring<string>::iterator it=text_ring.begin(); it!=text_ring.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    for(const string &value: text_ring) {
        cout << value << " ";
    }
    cout << endl;
}

void Cpp11::cpp11_beauty() {
    int value{5};
    cout << value << endl;

    string text{"hello"};
    cout << text << endl;

    int numbers[]{1, 2, 3, 4};
    cout << numbers[1] << endl;

    int *pInts = new int[4] {1, 2, 3, 4};
    cout << pInts[1] << endl;
    delete[] pInts;

    int *value1{}; // = int *p nullptr
    cout << value1 << endl;

//    int *pSomething{&value};
    int *pSomething{nullptr}; // NULL -> nullptr
    cout << *pSomething << endl;

    cout << pSomething << endl;

    int numbers1[5]{};
    cout << numbers1[1] << endl;

    struct {
        int value;
        string text;
    } s1 = {5, "hi"};

    cout << s1.text << endl;

    vector<string> strings{"one", "two", "three"};
    cout << strings[2] << endl;
}

void Cpp11::initializer_list() {
    vector<int> numbers { 1, 2, 3, 4, 5 };
    cout << numbers[2] << endl;
    InitListTest test { "apple", "orange", "banana" };
    test.print({"one", "two", "three", "four"});
}

void Cpp11::object_initialization() {
    ObjInitTest test;
    test.print();
    ObjInitTest test1(77);
    test1.print();

    ObjInitTest test2 = test1; // ^ we are using the default for '=' operator
    test2.print();
}

void lambda_test(void (*pFunc)()) {
    pFunc();
}

void Cpp11::lambda_functions() {
    auto func = [](){
        cout << "Hello world" << endl;
    };
    func();
    lambda_test(func);
    lambda_test([](){
       cout << "Hello again" << endl;
    });
    cout << typeid(func).name() << endl;
}