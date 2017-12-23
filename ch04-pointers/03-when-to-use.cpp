#include <iostream>

void compute(int input, int* output){
    *output = 2 * input;
}

int main() {
    /* This is the wrong way
     * inefficient in space and in time
    */
    // int num1 = 10;
    // int* num2 = new int;
    // compute(num1, num2);
    // std::cout << *num2 << std::endl;

    /* This is the right way */
    int num1 = 10;
    int num2;
    compute(num1, &num2);
    std::cout << num2 << std::endl;
}
