#include <iostream>

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

void showNodes(studentCollection sc) {
    listNode * node = sc;
    int i = 0;
    while (node != NULL) {
        std::cout << node->studentNum << ':' << node->grade << std::endl;
        node = node->next;
        i++;
    }
}

void addRecord(studentCollection &sc, int studentNum, int grade) {
    listNode * newNode = new listNode;
    newNode->studentNum = studentNum;
    newNode->grade = grade;
    newNode->next = sc;
    sc = newNode;
}

double averageRecord(studentCollection sc) {
    if (sc == NULL) return 0;
    double sum = 0;
    int count = 0;
    listNode * loopPtr = sc;
    while (loopPtr != NULL){
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum/count;
    return average;
}

int main() {
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1001; node1->grade = 85;
    listNode * node2 = new listNode;
    node2->studentNum = 1002; node2->grade = 95;
    listNode * node3 = new listNode;
    node3->studentNum = 1003; node3->grade = 90;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    showNodes(sc);

    std::cout << "Adding node" << std::endl;
    addRecord(sc, 1274, 91);
    showNodes(sc);

    std::cout << "Grade average" << std::endl;
    std::cout << averageRecord(sc) << std::endl;
}
