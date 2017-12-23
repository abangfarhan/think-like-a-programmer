#include <iostream>

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

void showNodes(studentCollection sc) {
    listNode * currentNode = sc;
    while (currentNode != NULL) {
        std::cout << currentNode->studentNum << ':' << currentNode-> grade << std::endl;
        currentNode = currentNode->next;
    }
}

void removeRecord(studentCollection &sc, int targetNum) {
    listNode * prevNode = 0;
    listNode * currentNode = sc;
    while (currentNode != NULL) {
        if (currentNode->studentNum == targetNum) {
            if (prevNode == 0) {
                sc = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            delete[] currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

int main() {
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1001; node1->grade = 80;
    listNode * node2 = new listNode;
    node2->studentNum = 1002; node2->grade = 85;
    listNode * node3 = new listNode;
    node3->studentNum = 1003; node3->grade = 95;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    showNodes(sc);

    removeRecord(sc, 1002);
    removeRecord(sc, 1001);
    showNodes(sc);
}
