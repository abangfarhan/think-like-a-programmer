#include <iostream>

int * foo(){
    int * bar = new int;
    *bar = 50;
    return bar;
}

void baz(int &num) {
    std::cout << &num << std::endl;
    std::cout << num << std::endl;
    num += 1;
}
int main() {
    /*
     *char charArray[3] = {'a','b'};
     *std::cout << charArray << std::endl;
     *char * charPointer = new char[2];
     *charPointer[0] = 'a'; charPointer[1] = 'b';
     *std::cout << charPointer << std::endl;
     */
    /*
     *int num = 20;
     *baz(num);
     *std::cout << &num << std::endl;
     *std::cout << num << std::endl;
     */

    for (int i=0; i<10; i++) {
        std::cout << i << std::endl;
        if (i==5)
            i += 1;
    }
}
