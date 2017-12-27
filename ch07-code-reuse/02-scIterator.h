#ifndef SC_ITERATOR_H
#define SC_ITERATOR_H

#include "../ch05-classes/01-student-record-class.h"
#include "01-student-collection.h"

class scIterator {
  public:
    scIterator();
    scIterator(studentCollection::studentNode * initial);
    void advance();
    bool pastEnd();
    studentRecord student();
  private:
    studentCollection::studentNode * currentIterator;
};

#endif
