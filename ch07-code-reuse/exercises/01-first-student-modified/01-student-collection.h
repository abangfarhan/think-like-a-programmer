#ifndef STUDENT_COLLECTION_H
#define STUDENT_COLLECTION_H

#include <iostream>
#include <string.h> // necessary for strcmp
#include "01-student-record-class.h"

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
    void setFirstStudentPolicy(int selection);
    studentRecord firstStudent();
    studentRecord recordAt(int position);
    friend class scIterator;
    scIterator firstItemIterator();
  private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
    typedef bool (studentCollection::* firstStudentPolicy)(studentRecord r1, studentRecord r2);
    firstStudentPolicy _currentPolicy;
    void _setFirstStudentPolicy(firstStudentPolicy f);
    bool _higherGrade(studentRecord r1, studentRecord r2);
    bool _lowerStudentNumber(studentRecord r1, studentRecord r2);
    bool _nameComesFirst(studentRecord r1, studentRecord r2);
};

#endif
