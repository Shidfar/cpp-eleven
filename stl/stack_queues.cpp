//
// Created by Shidfar Hodizoda on 18/02/2018.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;

public:
    Test(string name): name(name) {
    }

    ~Test() {
//        cout << "Object destroyed" << endl;
    }

    void print() {
        cout << name << endl;
    }
};

int main() {
    // LIFO
    stack<Test> test_stack;
    test_stack.push(Test("Mike"));
    test_stack.push(Test("John"));
    test_stack.push(Test("Sue"));

    cout << endl;

    /*
     * This is invalid code object is destroyed

     Test &test1 = test_stack.top();
     test_stack.pop();
     test1.print(); // Reference points to destroyed object

     */
    while (!test_stack.empty()) {
        Test &test = test_stack.top();
        test.print();
        test_stack.pop();
    }

    cout << endl;

    // FIFO
    queue<Test> test_queue;
    test_queue.push(Test("Mike"));
    test_queue.push(Test("John"));
    test_queue.push(Test("Sue"));

    cout << endl;

    /*
     * This is invalid code object is destroyed

     Test &test1 = test_queue.top();
     test_queue.pop();
     test1.print(); // Reference points to destroyed object

     */

    test_queue.back().print();
    cout << endl;

    while (!test_queue.empty()) {
        Test &test = test_queue.front();
        test.print();
        test_queue.pop();
    }

    cout << endl;
    return 0;
}
