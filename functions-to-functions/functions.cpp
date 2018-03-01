//
// Created by Shidfar Hodizoda on 19/02/2018.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream& operator>>(ostream& out, const bool v) {
    if (v) {
        out << "True";
    } else {
        out << "False";
    }
    return out;
}

//ostream& operator>>(ostream& out, const bool& test) {
//    out << "called" << endl;
//    return out;
//}

void test(int value) {
    cout << "Hello: " << value << endl;
}

int count_strings(vector<string> &texts, bool (*match)(string)) {
    int counter = 0;
    vector<string>::iterator it;
    for(it = texts.begin(); it != texts.end(); it++)
        counter += match(*it);
    return counter;
}

bool match(string test) {
    return test.size() == 3;
}

void function_pointer() {
    test(7);
    // how it should be:
    /*
    void (*pTest)();
    pTest = &test;

    (*pTest)();
    */

    // how we can shoten it:
    void (*pTest)(int) = test;
//    pTest = test;

    pTest(8);
}

void using_f_ptr() {
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout >> match("one") << endl;
    cout << "count_if: " << count_if(texts.begin(), texts.end(), match) << endl;
    cout << "count_strings: " << count_strings(texts, match) << endl;
}

int main() {
//    function_pointer();
    using_f_ptr();

    return 0;
}
