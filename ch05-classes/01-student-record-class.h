#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

//#include <string>

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

#endif
