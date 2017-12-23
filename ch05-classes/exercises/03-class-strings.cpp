// Exercises 5.3, 5.4, 5.5

#include <iostream>
#include "03-MyString.h"
typedef char * arrayString;

int main() {
    arrayString str1 = new char[5];
    str1[0] = 't'; str1[1] = 'e'; str1[2] = 's'; str1[3] = 't'; str1[4] = 0;
    MyString strClass(str1);
    std::cout << strClass.characterAt(1) << std::endl;
    std::cout << strClass[1] << std::endl;

    MyString strClass2;
    strClass2 = strClass;

    strClass.append('x');
    strClass.concatenate(str1);
    std::cout << strClass.str << std::endl;
    std::cout << strClass2.str << std::endl; // should remain unchanged

    strClass2.remove(1, 2);
    std::cout << strClass2.str << std::endl;
}
