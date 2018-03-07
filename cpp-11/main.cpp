//
// Created by Shidfar Hodizoda on 04/03/2018.
//

//#include "Sugar.h"
#include <vector>
#include "Cpp11.h"

void cpp98() {
    int values[] = {1, 4, 5};
    cout << values[0] << endl;

    class C {
    public:
        string text;
        int id;
    };

    struct S {
        string text;
        int id;
    };

    struct S1 {
        string text;
        int id;
    } s1 = { "ca va", 2 }, s2 = { "bien", 2 };

    C c = { "Hello", 7 };
    S s = { "hi", 12 };

    cout << c.text << endl;
    cout << s.text << endl;
    cout << s1.text << endl;
    cout << s2.text << endl;

    vector<string> strs;
    strs.push_back("One");
    strs.push_back("Two");
    strs.push_back("Three");
};

int main() {
//    Sugar s;
//    s.run();
//    s.c11auto();
//    s.enhanced_for_loop();
    Cpp11 cpp11;
//    cpp11.nested_templates();
//    cpp98();
//    cpp11.cpp11_beauty();
//    cpp11.initializer_list();
//    cpp11.object_initialization();
    cpp11.lambda_functions();
    return 0;
}
