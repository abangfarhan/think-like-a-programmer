#include <iostream>
#include <stack>

struct node {
    int data;
    node * next;
};
typedef node * listPtr;

void displayListForwardRecursion(listPtr head) {
    if (head == NULL) return;
    std::cout << head->data << ' ';
    displayListForwardRecursion(head->next);
}

void displayListReversedRecursion(listPtr head) {
    if (head == NULL) return;
    displayListReversedRecursion(head->next);
    std::cout << head->data << ' ';
}

void displayListForwardIterative(listPtr head) {
    for (listPtr current = head; current != NULL; current = current->next)
        std::cout << current->data << ' ';
}

void displayListReversedIterative(listPtr head) {
    std::stack<listPtr> nodes;
    for (listPtr current = head; current != NULL; current = current->next)
        nodes.push(current);
    while (!nodes.empty()) {
        node * current = nodes.top();
        nodes.pop();
        std::cout << current->data << ' ';
    }
}

int main() {
    node * node1 = new node;
    node * node2 = new node;
    node * node3 = new node;
    node * node4 = new node;
    node * node5 = new node;

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;
    node4->data = 40;
    node5->data = 50;

    listPtr head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    node1 = node2 = node3 = node4 = node5 = NULL;

    displayListForwardRecursion(head);
    std::cout << std::endl;

    displayListReversedRecursion(head);
    std::cout << std::endl;

    displayListForwardIterative(head);
    std::cout << std::endl;

    displayListReversedRecursion(head);
    std::cout << std::endl;
}
