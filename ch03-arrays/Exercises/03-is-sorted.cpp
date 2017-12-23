#include <iostream>

bool isSorted(int intArray[], int ARRAY_SIZE){
    if(ARRAY_SIZE > 1){
        for(int i=1; i<ARRAY_SIZE; i++){
            if(intArray[i] < intArray[i-1])
                return false;
        }
    }
    return true;
}
int main(){
    const int ARRAY_SIZE = 5;
    int intArray[ARRAY_SIZE] = {1, 2, 3, 1, 5};
    std::cout << isSorted(intArray, ARRAY_SIZE) << std::endl;
}
