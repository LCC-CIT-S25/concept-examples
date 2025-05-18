#include <iostream>
#include "Sequence.h"


int main() {
    Sequence seq;

    for (int i=0; i < 20; i++) {
        std::cout << "Next: " << seq.Next() << std::endl;
    }

    for (int i = 0; i < 21; i++) {
        try {
            std::cout << "GetPast: " << seq.GetPast(i) << std::endl;
        } catch (std::range_error e) {
            std::cerr << "GetPast exception caught: " << e.what() << std::endl;
        }
    }


    return 0;
}