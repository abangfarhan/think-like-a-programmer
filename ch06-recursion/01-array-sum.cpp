#include <iostream>

int arraySumIterative(int arr[], int size) {
    int sum = 0;
    for (int i=0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int arraySumDelegate(int arr[], int size) {
    if (size == 0) return 0;
    int lastNumber = arr[size - 1];
    int allButLastSum = arraySumIterative(arr, size - 1);
    return lastNumber + allButLastSum;
}

int arraySumRecursive(int arr[], int size) {
    if (size == 0) return 0;
    int lastNumber = arr[size - 1];
    int allButLastSum = arraySumRecursive(arr, size - 1);
    return lastNumber + allButLastSum;
}

int main() {
    int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 40, 50};

    std::cout << arraySumIterative(arr, SIZE) << std::endl;
    std::cout << arraySumDelegate(arr, SIZE) << std::endl;
    std::cout << arraySumRecursive(arr, SIZE) << std::endl;
}
