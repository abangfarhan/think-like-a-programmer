#include <iostream>
// list is doubly linked list
#include <list>

struct student {
    int studentNum;
    int grade;
};
typedef std::list<student> studentList;

void showStudents(const studentList &myStudentList) {
    studentList::const_iterator iter = myStudentList.begin();
    while (iter != myStudentList.end()) {
        printf("Student %d's grade is %d \n", (*iter).studentNum, (*iter).grade);
        iter++;
    }
}

double averageRecord(const studentList &myStudentList) {
    studentList::const_iterator iter;
    iter = myStudentList.begin();
    double sum = 0;
    while (iter != myStudentList.end()) {
        sum += (*iter).grade;
        iter++;
    }
    return (sum / myStudentList.size());
}

void addRecord(studentList &myStudentList, int studentNum, int grade) {
    student * temp = new student;
    temp->studentNum = studentNum;
    temp->grade = grade;
    myStudentList.push_back(*temp);
}

int main() {
    studentList myStudentList;
    addRecord(myStudentList, 1001, 85);
    addRecord(myStudentList, 1002, 93);
    addRecord(myStudentList, 1003, 90);

    showStudents(myStudentList);
    printf("Average grade: %.2f \n", averageRecord(myStudentList));
}
