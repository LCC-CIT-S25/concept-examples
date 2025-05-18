#include <iostream>

#include "MyClass.h"

int main() {
    {
        MyClass m1("a");
        std::cout << "inner" << std::endl;
    }

    MyClass* mine = new MyClass("my dynamic class");

    std::cout << mine->getName() << std::endl;
    mine->setValue(3);
    std::cout << mine->getValue() << std::endl;
    // `a->b` == `(*a).b`
    (*mine).setValue(4);
    std::cout << mine->getValue() << std::endl;

    std::cout << *mine << std::endl;

    delete mine;

    std::cout << "test" << std::endl;

    return 0;
}