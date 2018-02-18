//
// Created by Shidfar Hodizoda on 17/02/2018.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    map <string, int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    ages["Mike"] = 70;

//    pair<string, int> add_to_map("Peter", 100);
//    ages.insert(add_to_map);
//    ages.insert(pair<string, int>("Pair", 100))
    ages.insert(make_pair("Peter", 100));

    cout << ages["Raj"] << endl;
    if (ages.find("Vicky 1") != ages.end())
        cout << "Found Vicky " << ages["Vicky"] << endl;
    else
        cout << "Key not find" << endl;

//    for (map<string, int>::iterator it=ages.begin(); it != ages.end(); it++) {
//    for (auto it = ages.begin(); it != ages.end(); it++) {
//        cout << it->first << " : " << it->second <<endl;
//    }

    for (auto& it : ages) {                 // Range based loop (c++11)++
        cout << it.first << " : " << it.second <<endl;
    }

//    for (map<string, int>::iterator it=ages.begin(); it != ages.end(); it++) {
//        pair<string, int> age = *it;
//        cout << age.first << " : " << age.second <<endl;
//    }


//    for (auto&& [f, s] : ages) {          // in standard (c++14)++
//        cout << f << " : " << s <<endl;   // (use it with -std=c++1z)
//    }

    return 0;
}
