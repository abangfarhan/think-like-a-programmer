#include "02-scIterator.h"

scIterator::scIterator() {
    currentIterator = NULL;
}
scIterator::scIterator(studentCollection::studentNode * initial) {
    currentIterator = initial;
}
void scIterator::advance() {
    if (currentIterator != NULL)
        currentIterator = currentIterator->next;
}
bool scIterator::pastEnd() {
    return currentIterator == NULL;
}
studentRecord scIterator::student() {
    if (currentIterator == NULL) {
        studentRecord dummyRecord;
        return dummyRecord;
    } else {
        return currentIterator->studentData;
    }
}
