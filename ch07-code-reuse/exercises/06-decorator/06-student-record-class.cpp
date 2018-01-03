#include <iostream>
#include "06-student-record-class.h"

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

// ----- student with title ------ //

withTitle::withTitle(std::string newTitle, Interface *core): Wrapper(core) {
    _title = newTitle;
}

std::string withTitle::title() {
    return _title;
}

void withTitle::showStudentProperties() {
    Wrapper::showStudentProperties();
    std::cout << "Paper Title  : " << _title << std::endl;
}

// ----- student with year ------ //
withYear::withYear(int newYear, Interface *core): Wrapper(core) {
    _year = newYear;
}

int withYear::year() {
    return _year;
}

void withYear::showStudentProperties() {
    Wrapper::showStudentProperties();
    std::cout << "Year Enter   : " << _year << std::endl;
}
