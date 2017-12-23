#include "01-student-record-class.h"
class studentCollection {
  private:
    struct studentNode {
        studentRecord studentData;
        studentNode * next;
    };
  public:
    studentCollection();
    ~studentCollection();
    studentCollection(const studentCollection &original); // copy constructor
    //void addRecord(int studentNumber, std::string newName, int newGrade);
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    studentCollection& operator=(const studentCollection & rhs);
  private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};
