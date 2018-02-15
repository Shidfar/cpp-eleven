//
// Created by Shidfar Hodizoda on 15/02/2018.
//

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1) // remove the padding that is appended to the struct py default

struct Person
{
    char name[50];
    int age;
    double height;
};

#pragma pack(pop) // <- remove the pack so that after this point padding is added back

int main() {
    cout << sizeof(Person) <<endl;

    Person someone = {"Frodo", 220, 0.8};

    // Writing binary file
    string filename = "test.bin";
    ofstream output_file;
    output_file.open(filename, ios::binary); // ios::binary|ios::out
    if(output_file.is_open()) {
//        output_file.write((char *) &someone, sizeof(Person)); // <- old casting
        output_file.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        output_file.close();
    } else {
        cout <<"Could not create binary file " + filename <<endl;
    }


    // Read binary file
    Person someone_else = {};
    ifstream input_file;
    input_file.open(filename, ios::binary); // ios::binary|ios::in
    if(input_file.is_open()) {
//        input_file.read((char *) &someone, sizeof(Person)); // <- old casting
        input_file.read(reinterpret_cast<char *>(&someone_else), sizeof(Person));
        input_file.close();
    } else {
        cout <<"Could not read binary file " + filename <<endl;
    }

    cout <<someone_else.name <<", " <<someone_else.age <<", " <<someone_else.height <<". " <<endl;

    return 0;
}

// clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp -> a.out
// clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp -o run -> run (executable)
