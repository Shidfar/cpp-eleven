//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(): name(""), age(-1) {

    }

    Person(const Person &other) {
        cout <<"Copy constructor is running" <<endl;
        name = other.name;
        age = other.age;
    }

    Person(string name, int age) :
//            name(move(name)), age(age) {   // will automatically remove the name refs (moving objects newer way)
//            name(static_cast<typename std::remove_reference<string>::type&&>(name)), // moving objects manual c++11 way
//            age(age) {
        name(name), age(age) {
    }

    void print() const {
        cout << name <<": " << age << flush;
    }

    void print() {
        cout << name <<": " << age << flush;
    }

    bool operator<(const Person &other) const {
        if(name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }
};

void objects_as_values() {
    map<int, Person> people;
//    Person p = Person("Mike", 40);
    people[0] = Person("Mike", 40);
    people[1] = Person("Vicky", 30);
    people[2] = Person("Raj", 20);
//    people.insert(make_pair(55, Person("Bob", 45)));
//    people.insert(make_pair(25, Person("Sue", 24)));

    for (map<int, Person>::iterator it = people.begin();
         it != people.end(); it++) {
        cout <<it->first << " -> " << flush;
        it->second.print();
    }
}

void objects_as_keys() {
    map<Person, int> people;
    people[Person("Mike", 40)] = 40;
    people[Person("Mike", 444)] = 123;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    for(map<Person, int>::iterator it = people.begin();
            it != people.end(); it++) {
        cout << it->second << ": " << flush;
        it->first.print();
        cout << endl;
    }
}

int main() {
//    objects_as_values();
    objects_as_keys();
    return 0;
}