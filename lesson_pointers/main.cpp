#include <iostream>

int main() {
    int a = 5;
    int b = 2;

    std::cout << "size of int `a`: " << sizeof(int) << " " << sizeof(a) <<std::endl;

    /*
     * "address of" operator
     * uses the `&` before a variable
     *
     * possible room for ambiguity
     * `a & b` (binary operator for logical AND)
     *
     * address of operator has a relatively high precedence
     * a + &b
    */

    std::cout << "addresses of `a` and `b` " << &a << " " << &b << std::endl;

    /* How to store an address?
     *
     * Answer: pointers!
     *
     * We use another character `*` to modify the type declaration
     */

    int* pa = &a;
    std::cout << "pa: " << pa << std::endl;

    /* What can we do with a pointer?
     * We can access the value stored there
     */

    /* dereference a pointer using `*`, access the value stored at that address */
    std::cout << "*pa " << *pa << " a " << a << std::endl;

    a++;
    std::cout << "*pa " << *pa << " a " << a << std::endl;

    /*
     * arrays are really pointers!
     */

    int array[] = {1, 2, 3, 4, 5}; // sizeof(array) == sizeof(int) * 5 == 20 bytes
    /*
    int a0 = 1;
    int a1 = 2;
    int a2 = 3;
    ...
    */

    for (int i = 0; i < 5; i++) {
        std::cout << "address of array[" << i << "]: " << &array[i] << std::endl;
    }

    std::cout << "array: " << array <<std::endl;

    /* pointers are an integral type
     * This means we can add, subtract, or do other math with them!
     */
    for (int i = 0; i < 5; i++) {
        std::cout << "address of array[" << i << "]: " << &array[i] <<
            " (array + i): " << (array + i) << std::endl;
    }

    /* This is why we use zero indexing
     *
     * The `[]` to reference an array element is equivalent to moving forward the
     * correct number of bytes to read another of the same type.
     *
     * ## Pointer Arithmatic
     * `*(array + 1)` is equivalent to `array[1]`
     */


    for (int i = 0; i < 5; i++) {
        std::cout << "array[" << i << "]: " << array[i] <<
            " *(array + i): " << *(array + i) << std::endl;
    }

    return 0;
}