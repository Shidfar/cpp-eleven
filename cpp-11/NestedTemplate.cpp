//
// Created by Shidfar Hodizoda on 04/03/2018.
//

#include "NestedTemplate.h"

void NestedTemplate::run() {
//    ring<int>::iterator p;
//    p.print();
//    p.inform();
//    ring<double>::terminator a;
//    a.warn();

    ring<string>text_ring(3);
    text_ring.add("one");
    text_ring.add("two");
    text_ring.add("three");
    text_ring.add("four");

    for(int i=0; i<text_ring.size(); i++) {
        cout << text_ring.get(i) << endl;
    }
//    for(auto it=text_ring.begin(); it!=text_ring.end(); it++) {
//        cout << *it << endl;
//    }
//    cout << endl;
//
//    for(string value: text_ring) {
//        cout << value << endl;
//    }
}
