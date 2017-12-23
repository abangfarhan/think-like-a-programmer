#include <iostream>

int compareFunc(const void* voidA, const void* voidB){
    int* intA = (int*)(voidA);
    int* intB = (int*)(voidB);
    return *intA - *intB; // ascending order
    // return *intB - *intA; // descending order
}

void printArray(int intArray[], int ARRAY_SIZE){
    std::cout << "{";
    for (int i=0; i<ARRAY_SIZE; i++)
        std::cout << intArray[i] << ", ";
    std::cout << "}" << std::endl;
}

// void printArray(int intArray[], int ARRAY_SIZE){
//     for (int i=0; i<ARRAY_SIZE; i++){
//         std::cout << intArray[i] << ' ';
//     }
//     std::cout << std::endl;
// }

int main(){
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {10, 4, 2, 7, 5, 6, 5, 1, 10, 8};
    std::cout << "Original array: ";
    printArray(intArray, ARRAY_SIZE);

    qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
    std::cout << "Sorted array:   ";
    printArray(intArray, ARRAY_SIZE);

    int mostFrequent;
    int highestFrequency = 0;
    int currentFrequency = 0;
    std::cout << "Finding the mode..." << std::endl;
    for (int i=0; i<ARRAY_SIZE; i++){
        currentFrequency++;
        if (i == ARRAY_SIZE-1 || intArray[i] != intArray[i+1]){
            if (currentFrequency > highestFrequency){
                highestFrequency = currentFrequency;
                mostFrequent = intArray[i];
                std::cout << "Highest so far is " << mostFrequent << " which occurs " << highestFrequency << " times." << std::endl;
            }
            currentFrequency = 0;
        }
    }

    std::cout << "The mode is " << mostFrequent << " which appears " << highestFrequency << " times." << std::endl;
    return 1;
}
