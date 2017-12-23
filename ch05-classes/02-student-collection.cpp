#include <iostream>
//#include <string>
#include "02-student-collection.h"

studentCollection::studentCollection() {
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent) {
    studentNode * newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
    studentNode * currentNode = _listHead;
    while (currentNode != NULL && currentNode->studentData.studentID() != idNum)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
//      studentRecord dummyRecord(-1, -1, "");
        std::cout << "Record not found, returning dummy record..." << std::endl;
        studentRecord dummyRecord;
        return dummyRecord;
    }
    return currentNode->studentData;
}

void studentCollection::removeRecord(int idNum) {
    studentNode * prevNode = NULL;
    studentNode * currentNode = _listHead;
    while (currentNode != NULL && currentNode->studentData.studentID() != idNum) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) return;
    if (prevNode == NULL) {
        // when currentNode is first item
        _listHead = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }
    delete currentNode;
}

void studentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode * tempNode = listPtr;
        listPtr = listPtr->next;
        delete tempNode;
    }
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
    std::cout << "Class Deleted" << std::endl;
    // TODO check with GDB that the nodes are actually deleted
}

studentCollection::studentList studentCollection::copiedList(const studentList original) {
    if (original == NULL) return NULL;

    studentNode * oldCurrentNode = original;
    studentNode * newCurrentNode = new studentNode;
    studentList newList = newCurrentNode;
    newCurrentNode->studentData = oldCurrentNode->studentData;
    oldCurrentNode = oldCurrentNode->next;
    while (oldCurrentNode != NULL) {
        newCurrentNode->next = new studentNode;
        newCurrentNode = newCurrentNode->next;
        newCurrentNode->studentData = oldCurrentNode->studentData;
        oldCurrentNode = oldCurrentNode->next;
    }
    newCurrentNode->next = NULL;
    return newList;
    //while (currentNode != NULL) {
        //newNode->studentData = currentNode->studentData;
        //newNode->next = new studentNode;
        //if (currentNode->next != NULL)
            //newNode = newNode->next;
        //else
            //newNode = NULL;
        //currentNode = currentNode->next;
    //}
}

studentCollection& studentCollection::operator=(const studentCollection &rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

studentCollection::studentCollection(const studentCollection &original) {
    _listHead = copiedList(original._listHead);
}
