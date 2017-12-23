#include <iostream>

int main() {
    int ARRAY_SIZE;
    std::cout << "Number of survey responses: ";
    std::cin >> ARRAY_SIZE;
    int *surveyData = new int[ARRAY_SIZE];
    // why do it like that instead of this:
    // int surveyData[ARRAY_SIZE];
    // if we do it like that, we cannot delete surveyData
    // And we want to emphasize that the array size is decided at run time

    for(int i=0; i<ARRAY_SIZE; i++) {
        std::cout << "Survey response " << i + 1 << ": ";
        std::cin >> surveyData[i];
    }

    //delete[] surveyData;
    // the code below will still be run after delete[]
    // but it will spout nonsensical numbers
    for(int i=0; i<ARRAY_SIZE; i++) {
        std::cout << surveyData[i] << std::endl;
    }

    return 1;
}
