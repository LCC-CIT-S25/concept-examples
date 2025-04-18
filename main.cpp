#include <iostream>

#include "image_demo.h"

using namespace std;

int main() {

    const size_t D1 = 2;
    const size_t D2 = 3;
    unsigned char arr[D1][D2] =
        {
        {1,2,3},
        {4,5,6},
        };

    cout << "element size: " << sizeof(arr[0][0]) << endl;
    cout << "row size:     " << sizeof(arr[0]) << endl;
    cout << "array size:   " <<sizeof(arr) << endl;

    const uint32_t h = 512;
    const uint32_t w = 1024;
    uint8_t data[h*w][3];

    demo_image(data, h, w);
    write_image((data),h,w,"test.bmp");

    return 0;
}
