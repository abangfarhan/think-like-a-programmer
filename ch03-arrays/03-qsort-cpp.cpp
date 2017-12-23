#include <iostream>

using namespace std;

int compareFunc(const void* voidA, const void* voidB){
    int* intA = (int*)(voidA);
    int* intB = (int*)(voidB);
    // std::cout << *intA << ' ' << *intB << std::endl;
    return *intA - *intB; // ascending order
    // return *intB - *intA; // descending order
}

int main(){
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
    cout << "Unsorted array:" << endl;
    for (int i=0; i<ARRAY_SIZE; i++){
        cout << intArray[i] << ' ';
    }
    cout << endl;

    cout << "Sorted array (ascending):" << endl;
    // 4 arguments below are strictly necessary for qsort
    qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
    for (int i=0; i<ARRAY_SIZE; i++){
        cout << intArray[i] << ' ';
    }
}
