//
// Created by Shidfar Hodizoda on 03/03/2018.
//

#include <iostream>
using namespace std;

struct MatchTest {
    bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text) {

}

int main() {
    MatchTest pred;
    string val = "lion";
    cout << pred(val) << endl;
    return 0;
}
