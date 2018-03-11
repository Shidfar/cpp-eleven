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

#define Test LambdaTest
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
    Test t;
    t.run();
}

#undef Test

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

#define Child DelegateChild
#define Parent DelegateParent
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
    Parent parent("hello");
    Child child;
}

#undef Child
#undef Parent

#define Test ElOpTest
class ElOpTest {
private:
    static const int SIZE { 100 };

    int *_pBuffer = { nullptr };

public:
    ElOpTest() {
        cout << " [ ] constructor" << endl;
//        _pBuffer = new int[SIZE](0);   // allocating memory of SIZE
        //                     1. ^ setting allocated memory to 0
//        memset(_pBuffer, 0, sizeof(int)*SIZE);  // 2. setting allocated memory to 0
        _pBuffer = new int[SIZE]{};
        //                   3. ^ third way of setting memory to zero
    }
    ElOpTest(int i) {
        cout << " [p] parameter constructor" << endl;
        _pBuffer = new int[SIZE]{};
        for (int i=0; i<SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }
    ElOpTest(const ElOpTest& other) {
        cout << " [cp] copy constructor" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }
    ElOpTest(ElOpTest &&other) {
        cout << " [mv] move constructor " << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }
    ElOpTest&operator=(const ElOpTest& other) {
        cout << " [=] assignment operator" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }
    ElOpTest&operator=(ElOpTest &&other) {
        cout << " [mv] move assignment operator " << endl;
        delete [] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
        return *this;
    }
    ~ElOpTest() {
        cout << " [~] destructor" << endl;
        delete[] _pBuffer;
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

void check_integer(const int& value) {
    cout << "lValue " << value << endl;
}

void check_integer(int&& value) {
    cout << "rValue " << value << endl;
}

void Cpp11::elision_n_optimization() {
    Test test1 = getElOpTest();
    vector<Test> vec;

    vec.push_back(Test());
    cout << test1 << endl;

    int value1 = 7;

    int *pValue1 = &value1;
//    int *pValue2 = &7;          // <- cannot
    Test *pTest1 = &test1;
//    Test *pTest2 = &getTest();  // <- cannot

    int *pValue3 = &++value1;
    cout << *pValue3 << endl;

//    int *pValue4 = &value1++;   // <- cannot

//    int *s = &(7 + value1);       // <- cannot

    cout << " =========== + =========== " << endl;

    Test &rTest1 = test1;
//    Test &rTest2 = getElOpTest();       // we can't do this because we are getting
                                          // a reference from an object that doesn't exist
    const Test &rTest2 = getElOpTest();   // on the other hand making the reference const
                                          // let's us to hold the return value of the function
                                          // as long as this variable exists...
    Test test2(Test(1));                  // <- using copy constructor...
}

void check(const Test& value) {
    cout << "lValue function" << endl;
}

void check(Test&& value) {
    cout << "rValue function" << endl;
}

void Cpp11::r_value_references() {
    Test test1 = getElOpTest();
    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    Test &ltest = test1;
    Test &&rtest1 = Test();
    Test &&rtest2 = getElOpTest();

    check(test1);
    check(getElOpTest());
    check(Test());

    int integer = 0;
    check_integer(++integer);
    check_integer(integer++);
}

void Cpp11::move_constructor() {
    vector<Test> vec;
    vec.push_back(Test());
}

void Cpp11::move_assignment_operator() {
    Test test;
    test = getElOpTest();
}

#undef Test

#define Parent CastingParent
class CastingParent {
public:
    virtual void speak() {
        cout << "parent " << endl;
    }
};

class Brother: public CastingParent {

};

class Sister: public CastingParent {

};

void Cpp11::static_casts() {
    Parent parent;
    Brother brother;

    float value = 3.23;
    cout << value << endl;
    cout << (int) value << endl;
    cout << int(value) << endl;

    cout << static_cast<int>(value) << endl;

    Parent *pp = &brother;
    Brother *pb = static_cast<Brother *>(&parent);  // dangerous!!
    cout << pb << endl;

    Parent *ppb = &brother;
    Brother *pbb = static_cast<Brother *>(ppb);     // dangerous!!
    cout << pbb << endl;


//    Parent &&p = Parent();
    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();
}

void Cpp11::dynamic_casts() {
    Parent parent;
    Brother brother;

    Parent *ppb = &brother;
//    Parent *ppb = &parent;
    Brother *pbb = dynamic_cast<Brother *>(ppb);

    if(pbb == nullptr) {
        cout << "Invalid casting" << endl;
    } else {
        cout << pbb << endl;
    }
}

void Cpp11::reinterpret_casts() {
    Parent parent;
    Brother brother;
    Sister sister;

    Parent *ppb = &brother;
//    Parent *ppb = &parent;
    Sister *pss = reinterpret_cast<Sister *>(ppb);  // most dangerous! simply
                                                    // casts binary pointers
    if(pss == nullptr) {
        cout << "Invalid casting" << endl;
    } else {
        cout << pss << endl;
    }
}
#undef Parent

#define Test PerForTest
#define check pf_check
class PerForTest {

};

template <typename T>
void call(T &&arg) {
//    check(static_cast<T>(arg));
    check(forward<T>(arg));         // the same as above but more clear
}

void pf_check(Test &test) {
    cout << "lvalue " << endl;
}

void pf_check(Test &&test) {
    cout << "rvalue " << endl;
}

void Cpp11::perfect_forwarding() {
    Test test;
//    auto &&t = Test();
    auto &&t = test; // works because auto will collapse the rvalue reference
    call(test);
    call(Test());
}

#undef Test
