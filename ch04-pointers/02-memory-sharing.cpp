#include <iostream>

void refParamFunction(int &x) {
    // by using &, the program do not copy x
    // but rather just refer to the location of x
    x = 10;
}

int anotherFunction(const int &x){
    // by using & and const, the program will not copy x
    // and also won't be able to modify x (just like any function)
    return x + 10;
}

int main(){
    int number = 5;
    refParamFunction(number);
    std::cout << number << std::endl; // 10
}
