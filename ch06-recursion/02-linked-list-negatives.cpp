#include <iostream>

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

int listCountNegative(listPtr head) {
    if (head == NULL) return 0;
    int listCount = listCountNegative(head->next);
    if (head->data < 0) listCount++;
    return listCount;
}

int main() {
    listNode * node1 = new listNode;
    listNode * node2 = new listNode;
    listNode * node3 = new listNode;

    node1->data = 10;
    node2->data = -14;
    node3->data = -5;

    listPtr list1 = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    std::cout << listCountNegative(list1) << std::endl;
}
