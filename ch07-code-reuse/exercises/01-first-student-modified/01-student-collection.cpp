#include "01-student-collection.h"

studentCollection::studentCollection() {
    _listHead = NULL;
    _currentPolicy = NULL;
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

bool studentCollection::_higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}
bool studentCollection::_lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}
bool studentCollection::_nameComesFirst(studentRecord r1, studentRecord r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

void studentCollection::_setFirstStudentPolicy(firstStudentPolicy f) {
    _currentPolicy = f;
}

void studentCollection::setFirstStudentPolicy(Comparator comparator) {
    if (comparator == highestGrade)
        _setFirstStudentPolicy(&_higherGrade);
    else if (comparator == lowestStudentNumber)
        _setFirstStudentPolicy(&_lowerStudentNumber);
    else if (comparator == firstName)
        _setFirstStudentPolicy(&_nameComesFirst);
}

studentRecord studentCollection::firstStudent() {
    if (_currentPolicy == NULL) {
        std::cout << "No policy. Returning dummy record" << std::endl;
        studentRecord dummyRecord;
        return dummyRecord;
    }
    studentNode * currentNode = _listHead;
    studentRecord first = currentNode->studentData;
    currentNode = currentNode->next;
    while (currentNode != NULL) {
        // see https://stackoverflow.com/questions/10901959/function-pointers-in-c-error-must-use-or-to-call-pointer-to-memb
        if ((this->*_currentPolicy)(currentNode->studentData, first)) {
            first = currentNode->studentData;
        }
        currentNode = currentNode->next;
    }
    return first;
}

studentRecord studentCollection::recordAt(int position) {
    studentNode * currentNode = _listHead;
    int i = 0;
    while (currentNode != NULL && i < position) {
        i++;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        studentRecord dummyRecord;
        return dummyRecord;
    } else {
        return currentNode->studentData;
    }
}

// cannot define here! scIterator still not defined yet...
// scIterator studentCollection::firstItemIterator() {
//     return scIterator(_listHead);
// }
