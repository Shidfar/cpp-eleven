//
// Created by Shidfar Hodizoda on 15/02/2018.
//

#include <iostream>
#include <vector>
using namespace std;

void vectors1() {
    cout <<" ## vectors 1" <<endl;
//    vector<string> strings(5);
    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

//    strings[3] = "dog";

//    cout <<strings[1] <<endl;
//    cout <<strings.size() <<endl;

    for (int i=0; i<strings.size(); i++)
        cout << strings[i] <<endl;

    for (const auto &str : strings)
        cout << str <<endl;

    for(vector<string>::iterator i=strings.begin(); i!=strings.end(); i++)
        cout << *i <<endl;

    for(auto i=strings.begin(); i!=strings.end(); i++)
        cout << *i <<endl;
}
void vectors2() {
    cout <<" ## vectors 2" <<endl;
    vector<double> numbers(0); // <- (20, 1) will make all the values = 1
    cout <<"Size: " <<numbers.size() <<endl;
    unsigned long capacity = numbers.capacity();
    cout << "Capacity: " <<capacity <<endl;
    for(int i=0; i<10000; i++) {
        numbers.push_back(i);
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " <<capacity <<endl;
        }
    }
    numbers.push_back(10.2);
//    numbers.clear();
//    cout <<"Size: " <<numbers.size() <<endl;
//    cout << "Capacity: " <<numbers.capacity() <<endl;
//    numbers.resize(100);
    numbers.reserve(100000);
    cout <<numbers[22] <<endl;
    cout <<"Size: " <<numbers.size() <<endl;
    cout << "Capacity: " <<numbers.capacity() <<endl;
}
void grid_vector() {
    vector< vector <int> > grid(3, vector<int>(4, -1));
    grid[1].push_back(0);  // <- makes one row longer than the others...
//    for(auto &row : grid) {
//        for(auto &col : row) {
//            cout <<col <<" ";
//        }
//        cout <<endl;
//    }
    for(int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[i].size(); j++) {
            cout <<grid[i][j] <<" "; // <<flush;
        }
        cout <<endl;
    }
}
int main() {

//    vectors1();
//    vectors2();
    grid_vector();
    return 0;
}

// clang++ -std=c++11 -stdlib=libc++ -Wall vectors.cpp -o vectors
