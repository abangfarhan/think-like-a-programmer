#include <iostream>

struct treeNode {
    int data;
    treeNode * left;
    treeNode * right;
};
typedef treeNode * treePtr;

int binaryTreeLargest(treePtr root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    int leftMax = binaryTreeLargest(root->left);
    int rightMax = binaryTreeLargest(root->right);
    int maxNum = root->data;
    if (leftMax > maxNum) maxNum = leftMax;
    if (rightMax > maxNum) maxNum = rightMax;
    return maxNum;
}

int main() {
    treeNode * node1 = new treeNode;
    treeNode * node2 = new treeNode;
    treeNode * node3 = new treeNode;

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    treePtr root = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;
    node1 = node2 = node3 = NULL;

    std::cout << binaryTreeLargest(root) << std::endl;
}
