// Exercise 6.9, 6.10 and 6.11
// Node can be degenerate
#include <iostream>

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};
typedef treeNode * treePtr;

bool isBinaryHeap(treePtr rootPtr) {
    if (rootPtr == NULL) return true;
    bool isHighest = true;
    bool isHighestLeft = true;
    bool isHighestRight = true;
    if (rootPtr->left != NULL) {
        if (rootPtr->left->data > rootPtr->data)
            isHighest = false;
        isHighestLeft = isBinaryHeap(rootPtr->left);
    }
    if (rootPtr->right != NULL) {
        if (rootPtr->right->data > rootPtr->data)
            isHighest = false;
        isHighestRight = isBinaryHeap(rootPtr->right);
    }
     return (isHighest && isHighestLeft && isHighestRight);
}

bool isBinarySearch(treePtr rootPtr) {
    if (rootPtr == NULL) return true;
    bool isNodeSearch = true;
    bool isNodeSearchLeft = true;
    bool isNodeSearchRight = true;
    if (rootPtr->left != NULL) {
        if (rootPtr->left->data > rootPtr->data)
            isNodeSearch = false;
        isNodeSearchLeft = isBinarySearch(rootPtr->left);
    }
    if (rootPtr->right != NULL) {
        if (rootPtr->right->data < rootPtr->data)
            isNodeSearch = false;
        isNodeSearchRight = isBinarySearch(rootPtr->right);
    }
    return (isNodeSearch && isNodeSearchLeft && isNodeSearchRight);
}

void unravelTree(treePtr rootPtr) {
    if (rootPtr == NULL) return;
    if (rootPtr->left != NULL)
        unravelTree(rootPtr->left);
    std::cout << rootPtr->data << ' ';
    if (rootPtr->right != NULL)
        unravelTree(rootPtr->right);
}

void searchTreeAddNum(treePtr & rootPtr, int newNum) {
    if (rootPtr == NULL) {
        rootPtr = new treeNode;
        rootPtr->data = newNum;
        rootPtr->left = NULL;
        rootPtr->right = NULL;
        return;
    }
    if (newNum < rootPtr->data)
        searchTreeAddNum(rootPtr->left, newNum);
    else
        searchTreeAddNum(rootPtr->right, newNum);
}

int main() {
    treeNode * node1 = new treeNode;
    treeNode * node2 = new treeNode;
    treeNode * node3 = new treeNode;
    treeNode * node4 = new treeNode;

    node1->data = 20;
    node2->data = 15;
    node3->data = 30;
    node4->data = 40;

    treePtr rootPtr = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = node4;
    node4->left = NULL;
    node4->right = NULL;
    node1 = node2 = node3 = node4 = NULL;

    std::cout << isBinaryHeap(rootPtr) << std::endl;
    std::cout << isBinarySearch(rootPtr) << std::endl;

    unravelTree(rootPtr);
    std::cout << std::endl;
    searchTreeAddNum(rootPtr, 50);
    unravelTree(rootPtr);
    std::cout << std::endl;
}
