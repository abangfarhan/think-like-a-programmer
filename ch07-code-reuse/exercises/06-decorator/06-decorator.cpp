#include <iostream>
#include "06-student-record-class.h"

int main() {
    // Result from googling suggested using Decorator Design Pattern
    // I follow implementation in https://sourcemaking.com/design_patterns/decorator/cpp/1

    Interface * s1;
    s1 = new studentRecord(91, 1001, "Mike");
    s1 = new withYear(2014, s1);
    s1 = new withTitle("Paper 1", s1);
    s1->title(); // fine

    Interface * s2;
    s2 = new studentRecord(93, 1002, "Bob");
    s2 = new withTitle("Paper 4", s2);
    s2 = new withYear(2016, s2);
    s2->title(); // error/wrong! FIXME! (but showStudentProperties still working tho)
    s2->test(); // fine
    // s2->title() still error even if returning "whatever" string
    // s2->title() and s2->test() are basically the same except the return type
    // for now I give up

    Interface * s3;
    s3 = new studentRecord(90, 1003, "Jan");
    s3 = new withTitle("Paper 9", s3);
    s3->title(); // fine
}
