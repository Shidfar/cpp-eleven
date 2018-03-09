//
// Created by Shidfar Hodizoda on 03/03/2018.
//

#include <iostream>
using namespace std;

struct Test {
    virtual bool operator()(string &text) = 0;
    virtual ~Test(){

    }
};

struct MatchTest: public Test {
    bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if (test(text)) {
        cout << "Text matches." << endl;
    } else {
        cout << "No match." << endl;
    }
}

int functors() {
    MatchTest pred;
    string val = "lion";
    cout << pred(val) << endl;
    MatchTest m;
    check("lion1", m);
    return 0;
}
