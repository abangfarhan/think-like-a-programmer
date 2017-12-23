#include <iostream>

void printArray(int intArray[], int ARRAY_SIZE){
    for (int i=0; i<ARRAY_SIZE; i++){
        std::cout << intArray[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4,5,9,12,-4,0,-57,30987,-287,1};
    printArray(intArray, ARRAY_SIZE);

    int start = 0;
    int end = ARRAY_SIZE-1;
    for (int i=start+1; i<=end; i++){
        for (int j=i; j>start && intArray[j-1]>intArray[j]; j--){
            int temp = intArray[j-1];
            intArray[j-1] = intArray[j];
            intArray[j] = temp;

            printArray(intArray, ARRAY_SIZE);
        }
    }

    // for (int i=0; i<ARRAY_SIZE; i++){
    //     std::cout << intArray[i] << ' ';
    // }
    // std::cout << std::endl;
    return 1;
}
