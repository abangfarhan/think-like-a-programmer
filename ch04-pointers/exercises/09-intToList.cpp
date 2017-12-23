#include <iostream>
struct intNode {
    int num;
    intNode * next;
};
typedef intNode * intList;

void printList(intList l) {
    intNode * currentNode = l;
    while (currentNode != NULL) {
        std::cout << currentNode->num;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

intList intToList(int num) {
    int mod = 10;
    intNode * currentNode = NULL;

    while (num > 0) {
        intNode * tempNode = currentNode;
        currentNode = new intNode;
        currentNode->num = (num%mod)/(mod/10);
        currentNode->next = tempNode;

        num = num - num%mod;
        mod *= 10;
    }

    intList l = currentNode;
}

int listToInt(intList l) {
    int num = 0;
    intNode * currentNode = l;
    while (currentNode != NULL) {
        num = num*10 + currentNode->num;
        currentNode = currentNode->next;
    }
    return num;
}

intList intListSum(intList l1, intList l2) {
    int num1 = listToInt(l1);
    int num2 = listToInt(l2);
    int newNum = num1 + num2;
    return intToList(newNum);
}

int main() {
    int num = 149;
    /* intList L;
     * intNode * n1 = new intNode;
     * intNode * n2 = new intNode;
     * intNode * n3 = new intNode;
     * n1->num = 1;
     * n2->num = 4;
     * n3->num = 9;

     * L = n1;
     * n1->next = n2;
     * n2->next = n3;
     * n3->next = NULL;
     * n1 = n2 = n3 = NULL;
     * printList(L);
     */

    intList myIntList1 = intToList(149);
    printList(myIntList1);

    intList myIntList2 = intListSum(myIntList1, myIntList1);
    printList(myIntList2);
}
