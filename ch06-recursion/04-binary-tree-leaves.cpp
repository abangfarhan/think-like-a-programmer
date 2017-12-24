#include <iostream>

class binaryTree {
  public:
    binaryTree();
    int publicCountLeaves();
  private:
    // NOTE: each node on binary tree assumed to be symmetric
    struct binaryTreeNode {
        int data;
        binaryTreeNode * left;
        binaryTreeNode * right;
    };
    typedef binaryTreeNode * treePtr;
    treePtr _root;
    int privateCountLeaves(treePtr rootPtr);
};

binaryTree::binaryTree() {
    // TODO: create a proper constructor class...
    // this is just for testing purpose
    binaryTreeNode * node1 = new binaryTreeNode;
    binaryTreeNode * node2 = new binaryTreeNode;
    binaryTreeNode * node3 = new binaryTreeNode;
    binaryTreeNode * node4 = new binaryTreeNode;
    binaryTreeNode * node5 = new binaryTreeNode;

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;
    node4->data = 40;
    node5->data = 50;

    _root = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
}

int binaryTree::privateCountLeaves(treePtr rootPtr) {
    if (rootPtr == NULL) return 0;
    if (rootPtr->left == NULL && rootPtr->right == NULL)
        return 1;
    int leftCount = privateCountLeaves(rootPtr->left);
    int rightCount = privateCountLeaves(rootPtr->right);
    return leftCount + rightCount;
}
int binaryTree::publicCountLeaves() {
    return privateCountLeaves(_root);
}

int main() {
    binaryTree bt1;
    printf("%d \n", bt1.publicCountLeaves());
}
