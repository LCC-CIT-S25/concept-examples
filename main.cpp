/*
 * CS162C - Lane Community College
 *
 * multidimensional arrays
 *
 */
#include <iostream>

#include "image_demo.h"

using namespace std;

int main() {

    const size_t D1 = 2;
    const size_t D2 = 3;
    unsigned int arr[D1][D2] =
        {
        {1,2,3},
        {4,5,6},
        };

    cout << "element size: " << sizeof(arr[0][0]) << endl;
    cout << "row size:     " << sizeof(arr[0]) << endl;
    cout << "array size:   " << sizeof(arr) << endl;

    cout << "num 1st index " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "num 2nd index " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    for (size_t i=0; i<D1; i++) {
        for (size_t j=0; j< sizeof(arr[0])/sizeof(arr[0][0]); j++) {
            cout << "[" << i << ", " << j << "]" << arr[i][j] << endl;
        }
    }

    // Red, Green, Blue (RGB color space)
    const size_t NUM_COLOR = 3;

    const uint32_t HEIGHT = 512;
    const uint32_t WIDTH = 1024;

    uint8_t data[HEIGHT][WIDTH][NUM_COLOR];

    // passing an array, all the dimension must be in the prototype except the most outer dimension
    // write(uint8_t data[][MAX_WIDTH][NUM_COLOR], size_t height, size_t actual_width, std:string filename);

    const string demofilename = "test.bmp";
    demo_image(reinterpret_cast<uint8_t*>(data), HEIGHT, WIDTH);
    write_image(reinterpret_cast<uint8_t*>(data), HEIGHT, WIDTH, demofilename);

    cout << "wrote demo image to " << demofilename << endl;
    return 0;
}
