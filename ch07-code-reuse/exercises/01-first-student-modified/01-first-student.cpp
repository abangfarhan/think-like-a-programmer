#include <iostream>
#include "01-student-record-class.h"
#include "01-student-collection.h"

// TODO: use enum instead int to select policy

int main() {
    studentRecord s1(90, 1001, "Mike");
    studentRecord s2(91, 1002, "Abdul");
    studentRecord s3(92, 1003, "Steve");
    studentCollection sc;
    sc.addRecord(s1);
    sc.addRecord(s2);
    sc.addRecord(s3);

    std::cout << "First Student = Highest Grade" << std::endl;
    sc.setFirstStudentPolicy(0);
    sc.firstStudent().showStudentProperties();

    std::cout << "First Student = Lowest Student Number" << std::endl;
    sc.setFirstStudentPolicy(1);
    sc.firstStudent().showStudentProperties();

    std::cout << "First Student = Name Comes First" << std::endl;
    sc.setFirstStudentPolicy(2);
    sc.firstStudent().showStudentProperties();
}
