#include <iostream>
struct charNode {
    char c;
    charNode * next;
};
typedef charNode * string;

void printString(string s);
int length(string s);
char characterAt(string s, int i);
void append(string &s, char newChar);
string copyString(string s);
void concatenate(string &s1, string s2);
void deleteString(string &s);
void removeChars(string &s, int start, int len);

int main() {
    string myString;
    charNode * c1 = new charNode;
    charNode * c2 = new charNode;
    charNode * c3 = new charNode;
    charNode * c4 = new charNode;
    c1->c = 't';
    c2->c = 'e';
    c3->c = 's';
    c4->c = 't';

    myString = c1;
    c1->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = NULL;
    c1 = c2 = c3 = c4 = NULL;

    printString(myString);
    append(myString, 'i');
    printString(myString);

    std::cout << characterAt(myString, 2) << std::endl;

    string duplicateString = copyString(myString);
    printString(duplicateString);

    concatenate(myString, duplicateString);
    deleteString(duplicateString);
    printString(myString);
    printString(duplicateString);

    removeChars(myString, 1, 3);
    printString(myString);
}

void printString(string s) {
    charNode * currentNode = s;
    while (currentNode != NULL) {
        std::cout << currentNode->c;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

int length(string s) {
    charNode * currentNode = s;
    int len = 0;
    while (currentNode != NULL){
        currentNode = currentNode->next;
        len++;
    }
    return len;
}

char characterAt(string s, int i) {
    charNode * currentNode = s;
    int counter = 0;
    while (currentNode != NULL) {
        if (counter == i)
            return currentNode->c;
        currentNode = currentNode->next;
        counter++;
    }
    std::cout << "i > length of s" << std::endl;
}

void append(string &s, char newChar) {
    charNode * newC = new charNode;
    newC->c = newChar;
    newC->next = NULL;

    if (s == NULL) {
        s = newC;
        return;
    }

    charNode * currentNode = s;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newC;
}

string copyString(string s) {
    charNode * currentNode = s;
    charNode * tempNode = new charNode;
    string newS = tempNode;
    while (currentNode != NULL) {
        tempNode->c = currentNode->c;
        if (currentNode->next != NULL) {
            tempNode->next = new charNode;
        } else {
            tempNode->next = NULL;
        }

        currentNode = currentNode->next;
        tempNode = tempNode->next;
    }
    return newS;
}

void concatenate(string &s1, string s2) {
    charNode * currentNode = s1;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = copyString(s2);
}

void removeChars(string &s, int start, int len) {
    charNode * currentNode = s;
    charNode * startNode;
    for (int i=1; i<start; i++) {
        currentNode = currentNode->next;
    }
    startNode = currentNode;

    currentNode = currentNode->next;
    for (int i=1; i<=len && currentNode != NULL; i++) {
        charNode * tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
    }

    startNode->next = currentNode;
}

void deleteString(string &s) {
    charNode * currentNode = s;
    while (currentNode != NULL) {
        charNode * tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
    }
    s = NULL; // s = currentNode;
}
