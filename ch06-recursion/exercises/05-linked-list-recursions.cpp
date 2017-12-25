// Exercise 6.5, 6.6, and 6.7

#include <iostream>
struct node {
    int num;
    node * next;
};
typedef node * nodePtr;

nodePtr arrToNode(int arr[], int size) {
    // helper function to create linked list
    if (size == 0) return NULL;
    node * current = new node;
    nodePtr head = current;
    current->num = arr[0];
    for (int i = 1; i < size; i++) {
        current->next = new node;
        current = current->next;
        current->num = arr[i];
    }
    current->next = NULL;
    return head;
}

int sumListIterative(nodePtr headPtr) {
    int sum = 0;
    for (node * current = headPtr; current != NULL; current = current->next) {
        sum += current->num;
    }
    return sum;
}

int sumListRecursion(nodePtr headPtr) {
    if (headPtr == NULL) return 0;
    return headPtr->num + sumListRecursion(headPtr->next);
}

int countTargetIterative(int target, nodePtr headPtr) {
    int targetCount = 0;
    for (node * current = headPtr; current != NULL; current = current->next) {
        if (current->num == target) targetCount++;
    }
    return targetCount;
}

int countTargetRecursion(int target, nodePtr headPtr) {
    if (headPtr == NULL) return 0;
    int targetCount = countTargetRecursion(target, headPtr->next);
    if (headPtr->num == target) targetCount++;
    return targetCount;
}

bool isOddParityIterative(nodePtr headPtr) {
    int ones = 0;
    for (node * current = headPtr; current != NULL; current = current->next) {
        if (current->num == 1) ones++;
    }
    return (ones%2 != 0);
}

bool isOddParityRecursion(nodePtr headPtr) {
    if (headPtr == NULL) return false;
    return (headPtr->num == 1 ^ isOddParityRecursion(headPtr->next));
}

int main() {
    int size = 10;
    int arr[size] = {1, 1, 1, 0, 0, 0, 1, 0, 1, 0};
    nodePtr headList = arrToNode(arr, size);
    std::cout << sumListIterative(headList) << std::endl;
    std::cout << sumListRecursion(headList) << std::endl;
    
    int target = 1;
    std::cout << countTargetIterative(target, headList) << std::endl;
    std::cout << countTargetRecursion(target, headList) << std::endl;

    std::cout << isOddParityIterative(headList) << std::endl;
    std::cout << isOddParityRecursion(headList) << std::endl;
}
