#include <iostream>

int main(){
    const int ARRAY_SIZE = 12;
    int intArray[ARRAY_SIZE] = {10, 4, 5, 7, 5, 6, 5, 1, 10, 8, 3, 1};

    // const int minResponse = 1
    const int maxResponse = 10;
    int histogram[maxResponse];
    for (int i=0; i<maxResponse; i++){
        histogram[i] = 0;
    }

    for (int i=0; i<ARRAY_SIZE; i++){
        histogram[intArray[i]-1]++;
    }

    int highestIndex = 0;
    for (int i=1; i<maxResponse; i++){
        if (histogram[highestIndex] < histogram[i]){
            highestIndex = i;
        }
    }
    highestIndex++; // because minResponse is 1
    std::cout << highestIndex << std::endl;

    return 1;
}
