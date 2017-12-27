#ifndef STUDENT_COLLECTION_H
#define STUDENT_COLLECTION_H

#include <iostream>
#include "../ch05-classes/01-student-record-class.h"
typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2);
// a type named firstStudentPolicy which is a pointer to a function
// that returns a bool and takes two parameters of type studentRecord

// forward declaration of scIterator
// without doing so will result in circular dependency
// because scIterator use studentCollection class, but
// studentCollection class require scIterator
// see https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes
// however, we still cannot define the firstItemIterator method on
// 01-student-collection.cpp since it requires full use of scIterator class
// thus we define it on the scIterator.cpp
class scIterator;

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
    void setFirstStudentPolicy(firstStudentPolicy f);
    studentRecord firstStudent();
    studentRecord recordAt(int position);
    friend class scIterator;
    scIterator firstItemIterator();
  private:
    firstStudentPolicy _currentPolicy;
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

#endif
