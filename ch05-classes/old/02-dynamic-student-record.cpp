#include <iostream>

struct student {
    int grade;
    int studentID;
    std::string name;
};

class studentRecord {
  public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);
    std::string letterGrade();
    void showStudentProperties();
  private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);
};

studentRecord::studentRecord() {
    setStudentID(-1);
    _grade = -1;
    setName("");
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName) {
    setStudentID(newID);
    setGrade(newGrade);
    setName(newName);
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if (isValidGrade(newGrade))
        _grade = newGrade;
}

int studentRecord::studentID() {
    return _studentID;
}

void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}

std::string studentRecord::name() {
    return _name;
}

void studentRecord::setName(std::string newName) {
    _name = newName;
}

void studentRecord::showStudentProperties() {
    std::cout << "ID           : " << _studentID    << std::endl;
    std::cout << "Name         : " << _name         << std::endl;
    std::cout << "Grade        : " << _grade        << std::endl;
    std::cout << "Grade Letter : " << letterGrade() << std::endl;
}

std::string studentRecord::letterGrade() {
    if(!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
}

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    return false;
}

class studentCollection {
  private:
    struct studentNode {
        studentRecord studentData;
        studentNode * next;
    };
  public:
    studentCollection();
    ~studentCollection();
    //void addRecord(int studentNumber, std::string newName, int newGrade);
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
  private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
};

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
        // currentNode is first item
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

int main() {
    studentCollection sc;
    studentRecord s1(90, 1001, "Abang");
    studentRecord s2(95, 1002, "Luthfianti");
    studentRecord s3(92, 1005, "Alya");
    studentRecord s4(84, 1003, "Faradisi");

    sc.addRecord(s1);
    sc.addRecord(s2);
    sc.addRecord(s3);
    sc.addRecord(s4);
    sc.recordWithNumber(1003).showStudentProperties();
    sc.removeRecord(1003);
    sc.recordWithNumber(1003).showStudentProperties();
}
