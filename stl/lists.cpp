//
// Created by Shidfar Hodizoda on 16/02/2018.
//

#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator i = numbers.begin();
    i++;
    numbers.insert(i, 10);
    cout <<"Element: " <<*i <<endl;


    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++)
        cout << *it <<endl;

    return 0;
}
