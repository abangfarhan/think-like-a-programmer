#include <iostream>

int countTargetIterative(int target, int arr[], int size) {
    int targetCounted = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) targetCounted++;
    }
    return targetCounted;
}

int countTargetRecursion(int target, int arr[], int size) {
    if (size == 0) return 0;
    int targetCounted = countTargetRecursion(target, arr, size - 1);
    if (arr[size - 1] == target) targetCounted++;
    return targetCounted;
}

int main() {
    int size = 10;
    int arr[size] = {100, 2, 3, 100, 4, 6, 7, 100, 9, 10};

    int target = 100;
    std::cout << countTargetIterative(target, arr, size) << std::endl;
    std::cout << countTargetRecursion(target, arr, size) << std::endl;
}
