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

// can only be defined here, because now both the
// studentCollection and scIterator classes have been declared completely
scIterator studentCollection::firstItemIterator() {
    return scIterator(_listHead);
}
