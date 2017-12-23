#include <iostream>

int main(){
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {1, 2, 5, 1, 0};
    int highestValue = intArray[0];
    for(int i=1; i<ARRAY_SIZE; i++){
        if (intArray[i] > highestValue)
            highestValue = intArray[i];
    }
    std::cout << highestValue << std::endl;

    int lowestValue = intArray[0];
    for(int i=1; i<ARRAY_SIZE; i++){
        if (intArray[i] < lowestValue)
            lowestValue = intArray[i];
    }
    std::cout << lowestValue << std::endl;

    return 1;
}
