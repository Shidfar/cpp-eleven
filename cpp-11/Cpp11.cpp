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

void greet_test(void (*greet)(string)) {
    greet("Bob");
}

void run_divide(double (*divide)(double a, double b)) {
    cout << "value: " << divide(9, 3) << endl;
}

void Cpp11::lambda_exp_parameters() {
    auto greet = [](string name) {
        cout << "hello " << name << endl;
    };
    greet("Mike");
    greet_test(greet);

    auto pDivide = [](double a, double b) -> double {
        if (b == 0.0) {
            return 0;
        }

        return (a/b);
    };
    cout << pDivide(10.0, 0) << endl;
    run_divide(pDivide);
}

void Cpp11::lambda_capture_exp() {
    int one = 1;
    int two = 2;
    int three = 3;
    // capture one and two by value
    [one, two](){ cout << "Hello " << one <<", " << two << endl; }();  // <- valid code :)

    // capture all local vars by value
    [=](){ cout << "Hello " << one <<", " << two << endl; }();  // <- valid code :)

    // capture all local vars by value but capture three by reference
    [=, &three](){ three = 7; cout << "Hello " << one <<", " << two << endl; }();  // <- valid code :)
    cout << three << endl;

    // capture all local vars by reference
    [&](){ three = 7; two = 8; cout << "Hello " << one <<", " << two << endl; }();  // <- valid code :)
    cout << two << endl;

    // capture all local vars by reference but two and three by value
    [&, two, three](){ one = 9; cout << "Hello " << one <<", " << two << endl; }();  // <- valid code :)
    cout << one << endl;
}

class LambdaTest {
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};
        auto pLambda = [&, this](){
            one = 111;
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

void Cpp11::lambda_capture_this() {
    LambdaTest t;
    t.run();
}

bool check(string &test) {
    return test.size() == 3;
}

class Check {
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

void run(function<bool(string&)> check) {
    string test = "stars";
    cout << check(test) << endl;
}

void Cpp11::function_types() {
    int size = 5;
    vector<string> vec{"one", "two", "three"};
    cout << count_if(vec.begin(), vec.end(), [=](string test) {
        return test.size() == size;
    }) << endl;

    cout << count_if(vec.begin(), vec.end(), check) << endl;

    cout << count_if(vec.begin(), vec.end(), check) << endl;

    cout << count_if(vec.begin(), vec.end(), check1) << endl;


    auto lambda = [=](string test) {
        return test.size() == size;
    };

    run(lambda);
    run(check1);
    run(check);

    function<int(int, int)> add = [](int one, int two) {
        return one + two;
    };
    cout << add(7, 3) << endl;
}

void Cpp11::mutable_lambda() {
    int cats = 5;
    [cats]() mutable {
        cats = 8;
        cout << cats << endl;
    }();
    cout << cats << endl;
}

class DelegateParent {
    int dogs;
    string text;
public:
    DelegateParent(): DelegateParent("hello") {
        dogs = 3;
        cout << "No parameter parent constructor" << endl;
    };

    DelegateParent(string text) {
        cout << "String parent constructor" << endl;
        dogs = 5;
        this->text = text;
    }
};

class DelegateChild: public DelegateParent {
public:
//    DelegateChild(): DelegateParent("hello") {
//        cout << "No parameter child constructor" << endl;
//    }
    DelegateChild() = default;
};

void Cpp11::deligating_constructors() {
    DelegateParent dParent("hello");
    DelegateChild child;
}
