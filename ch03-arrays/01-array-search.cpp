#include <iostream>

int main(){
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4,5,9,12,-4,0,-57,30987,-287,1};
    int targetValue = 12;
    int targetPos = 0;
    while ((intArray[targetPos] != targetValue) && (targetPos < ARRAY_SIZE))
        targetPos++;
    std::cout << targetPos << std::endl;
    return 1;
}
