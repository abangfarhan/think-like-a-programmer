#include <iostream>

int main() {
    int * variable1, variable2;
    variable2 = 10;
    variable1 = &variable2;
    *variable1 = 200;
    std::cout << variable2 << std::endl; // 200

    // new operator allows you to create a variable with
    // memory created on runtime
    double * doublePointer = new double; // why?
    *doublePointer = 35.4;
    // equivalent to
    // doublePointer[0] = 35.4
    double localDouble = *doublePointer;
    // equivalent to
    // double localDouble = doublePointer[0];
    std::cout << doublePointer << std::endl;
    delete doublePointer;
    std::cout << localDouble << std::endl;
    std::cout << doublePointer << std::endl;
    std::cout << *doublePointer << std::endl;
    // after delete doublePointer, the pointer still exist
    // but the pointee is not
    std::cout << "why not" << std::endl;
}
