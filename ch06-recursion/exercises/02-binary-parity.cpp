#include <iostream>

bool isOddParityIterative(int arr[], int size) {
    int ones = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) ones++;
    }
    return (ones%2 != 0);
}

bool isOddParityRecursion(int arr[], int size) {
    if (size == 0) return false;
    return (arr[size-1] == 1 ^ isOddParityRecursion(arr, size-1));
}

int main() {
    int size = 7;
    int binary[size] = {1, 1, 1, 0, 0, 1, 1};
    std::cout << isOddParityIterative(binary, size) << std::endl;
    std::cout << isOddParityRecursion(binary, size) << std::endl;
}
