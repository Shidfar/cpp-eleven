//
// Created by Shidfar Hodizoda on 12/03/2018.
//

#include <iostream>
#include "Picaso.h"

using namespace blackbox;
using namespace std;

int main() {
    Picaso picaso(800, 600);
    picaso.addRange(0.0, RGB(0, 0, 0));
    picaso.addRange(0.3, RGB(255, 0, 0));
    picaso.addRange(0.6, RGB(0, 255, 0));
    picaso.addRange(1.0, RGB(0, 0, 255));

    picaso.addZoom(Zoom((295), 202, 0.1));
    picaso.addZoom(Zoom((312), 304, 0.1));
    picaso.run("test.bmp");
    cout << "Finished." << endl;
    return 0;
}
