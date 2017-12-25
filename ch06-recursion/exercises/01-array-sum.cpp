#include <iostream>

int arrSumIterative(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int arrSumRecursion(int arr[], int size) {
    if (size <= 0) return 0;
    return arr[size - 1] + arrSumRecursion(arr, size - 1);
}

int main() {
    int size = 10;
    int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::cout << arrSumIterative(arr, size) << std::endl;
    std::cout << arrSumRecursion(arr, size) << std::endl;
}
