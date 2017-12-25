#include "LinkedList.h"

LinkedList::LinkedList() {
    _head = NULL
}

LinkedList::addNum(int newNum) {
    node * newNode = new node;
    newNode->data = newNum;
    newNode->next = _head->next;
    _head = newNode;
}
