//
// Created by Shidfar Hodizoda on 15/02/2018.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
//    vector<string> strings(5);
    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

//    strings[3] = "dog";

//    cout <<strings[1] <<endl;
//    cout <<strings.size() <<endl;

    for (const auto &str : strings)
        cout << str <<endl;

    for(vector<string>::iterator i=strings.begin(); i!=strings.end(); i++)
        cout <<*i <<endl;

    return 0;
}
