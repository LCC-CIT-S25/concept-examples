//
// Created by elms on 5/7/25.
//

#ifndef MYCLASS_H
#define MYCLASS_H


#include <string>

class MyClass {
private:
    int m_value;
    std::string m_name;


public:
    int id;

    MyClass(std::string name);
    ~MyClass();

    // getter/accessors
    std::string getName() {
        return m_name;
    }

    // setter/modifier
    bool setValue(int value) {
        if (value > 10) {
            return false;
        }
        m_value = value;
        return true;
    }

    int getValue() {
        return m_value;
    }

    friend std::ostream& operator<<(std::ostream& os, MyClass c);
};






#endif //MYCLASS_H
