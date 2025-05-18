//
// Created by elms on 5/7/25.
//

#include "MyClass.h"
#include <iostream>

MyClass::MyClass(std::string name)
    : m_name(name),
      id(-1),
      m_value(-10)
{
  // this - refers to the object itself
  // this is of type `MyClass*`
  //this->m_name = name;
  std::cout << "MyClass constructor " << m_name << " " <<
      m_value << " " <<
      id << " " << std::endl;
}

MyClass::~MyClass() {
  std::cout << "MyClass destructor:" << m_name << std::endl;
}

std::ostream& operator<<(std::ostream& os, MyClass c) {
  os << "MyClass(" << c.getName() << ", " << c.m_value <<")";
  return os;
}
