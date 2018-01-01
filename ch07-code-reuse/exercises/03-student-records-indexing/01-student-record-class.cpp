#include <iostream>
//#include <string>
#include "01-student-record-class.h"

studentRecord::studentRecord() {
    // setting illegitimate values for empty records
    setStudentID(-1);
    _grade = -1;
    // alternative: set a valid value, like 0
    //setGrade(0);
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
    /* possibly unnecessary validation.
     * this validation is unnecessary if you assign valid grade value to the
     * default constructor, like 0. Here we use -1 as the default value
     * So -1 returns an ERROR
     */
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
    /* alternative. might not work.
     * const int HIGHEST_GRADE_SCORE[] = {60, 67, 70, 73, 77, 80, 83, 87, 90, 93, 100};
     * int category = 0;
     * while (HIGHEST_GRADE_SCORE[category] <= _grade)
     *   //category++;
     * return GRADE_LETTER[category];    
     */
}

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    return false;
}
