#include <iostream>
#include "01-student-record-class.h"
#include "02-student-collection.h"

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
    std::cout << std::endl;
    sc.removeRecord(1003);
    sc.recordWithNumber(1003).showStudentProperties();
    std::cout << std::endl;

    studentCollection c1;
    studentCollection c2;
    studentRecord r1(85, 99837, "John");
    c2.addRecord(r1);
    studentRecord r2(77, 4765, "Elsie");
    c2.addRecord(r2);
    c1 = c2;
    c2.removeRecord(99837);
    c1.recordWithNumber(99837).showStudentProperties();

    std::cout << std::endl;

    studentCollection c3(c1);
    c1.removeRecord(99837);
    c3.recordWithNumber(99837).showStudentProperties();
}
