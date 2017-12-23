#include <iostream>

int main(){
    const int ARRAY_SIZE = 10;
    int gradeArray[ARRAY_SIZE] = {87,76,100,97,64,83,88,92,74,95};
    double sum = 0;
    for (int i=0; i<ARRAY_SIZE; i++){
        sum += gradeArray[i];
    }
    double average = sum/ARRAY_SIZE;
    std::cout << average << std::endl;
}
