#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#include <string>

class Interface {
  public:
    // base class
    virtual int grade() = 0;
    virtual void setGrade(int newGrade) = 0;
    virtual int studentID() = 0;
    virtual void setStudentID(int newID) = 0;
    virtual std::string name() = 0;
    virtual void setName(std::string newName) = 0;
    virtual std::string letterGrade() = 0;
    virtual void showStudentProperties() = 0;
    // optional methods
    virtual std::string title() = 0;
    virtual int test() = 0;
    virtual int year() = 0;
};

class studentRecord: public Interface {
  public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    // base class
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);
    std::string letterGrade();
    void showStudentProperties();
    // optional methods
    std::string title() {}
    int test() {}
    int year() {}
  private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);
};

class Wrapper: public Interface {
  public:
    Wrapper(Interface *inner)         {m_wrappee = inner;}
    ~Wrapper()                        {delete m_wrappee;}
    // base class methods
    int grade()                       {m_wrappee->grade();}
    void setGrade(int newGrade)       {m_wrappee->setGrade(newGrade);}
    int studentID()                   {m_wrappee->studentID();}
    void setStudentID(int newID)      {m_wrappee->setStudentID(newID);}
    std::string name()                {m_wrappee->name();}
    void setName(std::string newName) {m_wrappee->setName(newName);}
    std::string letterGrade()         {m_wrappee->letterGrade();}
    void showStudentProperties()      {m_wrappee->showStudentProperties();}
    // optional methods
    std::string title()               {m_wrappee->title();}
    int test()                        {m_wrappee->test();}
    int year()                        {m_wrappee->year();}
  private:
    Interface *m_wrappee;
};

class withTitle: public Wrapper {
  public:
    withTitle(std::string newTitle, Interface *core);
    std::string title();
    int test() {return 1009;}
    void showStudentProperties();
  private:
    std::string _title;
};

class withYear: public Wrapper {
  public:
    withYear(int newYear, Interface *core);
    int year();
    void showStudentProperties();
  private:
    int _year;
};

#endif
