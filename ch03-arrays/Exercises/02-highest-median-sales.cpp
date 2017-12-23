#include <iostream>

int compareFunc(const void* voidA, const void* voidB)
{
    int* intA = (int*)(voidA);
    int* intB = (int*)(voidB);
    return *intA - *intB;
}

double arrayMedian(int intArray[], int ARRAY_SIZE){
    int intArrayCopy[ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++){
        intArrayCopy[i] = intArray[i];
    }
    qsort(intArrayCopy, ARRAY_SIZE, sizeof(int), compareFunc);
    if (ARRAY_SIZE%2 == 0){
        return (double)(intArrayCopy[ARRAY_SIZE/2-1] + intArrayCopy[ARRAY_SIZE/2])/2;
    } else {
        return (double)intArrayCopy[ARRAY_SIZE/2];
    }
}

int main(){
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS]= {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {10, 20, 30, 40, 50, 61, 70, 80, 90, 100, 110, 120}
    };

    int highestMedianAgent = 0;
    double highestMedian = arrayMedian(sales[0], NUM_MONTHS);
    for(int agent=1; agent<NUM_AGENTS; agent++){
        double currentMedian = arrayMedian(sales[agent], NUM_MONTHS);
        if(currentMedian > highestMedian){
            highestMedian = currentMedian;
            highestMedianAgent = agent;
        }
    }
    std::cout << highestMedian << std::endl;
    std::cout << highestMedianAgent << std::endl;
}
