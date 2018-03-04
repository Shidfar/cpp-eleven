//
// Created by Shidfar Hodizoda on 04/03/2018.
//

#include "Sugar.h"

void Sugar::run() {
//    cout << "!!!Hello World!!!" << endl;
    string value;
    cout << typeid(value).name() << endl;

    decltype(value) name = "Bob";
    cout << typeid(name).name() << endl;
    cout << name << endl;
}

template <class T, class S>
auto test(T value, S value2) -> decltype(value + value2) {
    return value + value2;
}

int get() {
    return 999;
}

auto test2() -> decltype(get()) {
    return get();
}

void Sugar::c11auto() {
    auto value = 7;
    auto text = "Hello";

    cout << value << endl;
    cout << text << endl;
    cout << test(4, 5) << endl;
    cout << test2() << endl;
}

void Sugar::enhanced_for_loop() {
    auto texts = { "one", "two", "three" };
    for (auto text: texts) {
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(11);
    for(auto number: numbers) {
        cout << number << endl;
    }

    string hello = "Hello";
    for(auto c: hello) {
        cout << c << endl;
    }
}
