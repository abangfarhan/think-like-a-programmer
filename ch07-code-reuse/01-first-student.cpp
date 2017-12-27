#include <iostream>
#include <string.h> // necessary for strcmp
#include "../ch05-classes/01-student-record-class.h"
#include "01-student-collection.h"

bool higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}
bool lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}
bool nameComesFirst(studentRecord r1, studentRecord r2) {
    /* strcmp compares the first char of each strings
     * it takes two pointers as the argument
     * hence the reason we do c_str(), because that method
     * will return the pointer to the string.
     * This function will return 1 if the first char is earlier
     * in the alphabet list
     */
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

int main() {
    studentRecord s1(90, 1001, "Mike");
    studentRecord s2(91, 1002, "Abdul");
    studentRecord s3(92, 1003, "Steve");
    studentCollection sc;
    sc.addRecord(s1);
    sc.addRecord(s2);
    sc.addRecord(s3);
    std::cout << "First Student = Highest Grade" << std::endl;
    sc.setFirstStudentPolicy(&higherGrade);
    sc.firstStudent().showStudentProperties();
    std::cout << "First Student = Lowest Student Number" << std::endl;
    sc.setFirstStudentPolicy(&lowerStudentNumber);
    sc.firstStudent().showStudentProperties();
    std::cout << "First Student = Name Comes First" << std::endl;
    sc.setFirstStudentPolicy(&nameComesFirst);
    sc.firstStudent().showStudentProperties();
}
