// Exercise 5.7 and 5.8

#include <iostream>

class StudentCollection {
  public:
    StudentCollection();
    ~StudentCollection();
    StudentCollection& operator=(const StudentCollection & rhs);
    void addRecord(int newNum, float newGrade);
    float averageRecord();
    void showRecords();
    StudentCollection recordsWithinRange(float gradeLow, float gradeHigh);
  private:
    struct studentNode {
        int studentNum;
        float grade;
        studentNode * next;
    };
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

StudentCollection StudentCollection::recordsWithinRange(float gradeLow, float gradeHigh) {
    StudentCollection newRecord;
    studentNode * currentNode = _listHead;
    while (currentNode != NULL) {
        if (currentNode->grade >= gradeLow && currentNode->grade <= gradeHigh) {
            newRecord.addRecord(currentNode->studentNum, currentNode->grade);
        }
        currentNode = currentNode->next;
    }
    return newRecord;
}

StudentCollection::studentList StudentCollection::copiedList(const studentList original) {
    if (original == NULL) return NULL;

    studentNode * oldCurrentNode = original;
    studentNode * newCurrentNode = new studentNode;
    studentList newList = newCurrentNode;

    newCurrentNode->grade = oldCurrentNode->grade;
    newCurrentNode->studentNum = oldCurrentNode->studentNum;
    oldCurrentNode = oldCurrentNode->next;
    while (oldCurrentNode != NULL) {
        newCurrentNode->next = new studentNode;
        newCurrentNode = newCurrentNode->next;
        newCurrentNode->grade = oldCurrentNode->grade;
        newCurrentNode->studentNum = oldCurrentNode->studentNum;
        oldCurrentNode = oldCurrentNode->next;
    }
    newCurrentNode->next = NULL;
    return newList;
}

StudentCollection::StudentCollection() {
    _listHead = NULL;
}

StudentCollection& StudentCollection::operator=(const StudentCollection & rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

void StudentCollection::addRecord(int newNum, float newGrade) {
    studentNode * nextNode = _listHead;
    studentNode * newNode = new studentNode;
    newNode->studentNum = newNum;
    newNode->grade = newGrade;
    newNode->next = nextNode;
    _listHead = newNode;
}

float StudentCollection::averageRecord() {
    float sum = 0;
    int count = 0;
    studentNode * currentNode = _listHead;
    while (currentNode != NULL) {
        sum += currentNode->grade;
        count++;
        currentNode = currentNode->next;
    }
    return sum/count;
}

void StudentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode * tempNode = listPtr;
        listPtr = listPtr->next;
        delete tempNode;
    }
}

StudentCollection::~StudentCollection() {
    deleteList(_listHead);
}

void StudentCollection::showRecords() {
    studentNode * currentNode = _listHead;
    while (currentNode != NULL) {
        printf("Student number %d with grade = %.2f\n",
                currentNode->studentNum, currentNode->grade);
        currentNode = currentNode->next;
    }
}

int main() {
    StudentCollection sc;
    sc.addRecord(1, 81);
    sc.addRecord(23, 90);
    sc.addRecord(9, 85);
    sc.addRecord(19, 86);
    sc.showRecords();
    printf("sc grade average before: %.2f \n", sc.averageRecord());

    StudentCollection sc2;
    sc2 = sc;
    sc2.addRecord(21, 100);

    printf("sc grade average after: %.2f \n", sc.averageRecord());
    printf("sc2 grade average after: %.2f \n", sc2.averageRecord());

    StudentCollection sc3;
    sc3 = sc.recordsWithinRange(85, 90);
    sc3.showRecords();
}
