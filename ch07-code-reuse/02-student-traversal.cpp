#include <iostream>
#include <list>
#include "../ch05-classes/01-student-record-class.h"
#include "01-student-collection.h"
#include "02-scIterator.h"

// can only be defined here, because now both the
// studentCollection and scIterator classes have been declared completely
scIterator studentCollection::firstItemIterator() {
    return scIterator(_listHead);
}

int main() {
    studentRecord s1(90, 1001, "Mike");
    studentRecord s2(91, 1002, "Abdul");
    studentRecord s3(94, 1003, "Steve");
    studentCollection sc;
    sc.addRecord(s1);
    sc.addRecord(s2);
    sc.addRecord(s3);
    // // Inefficient Traversal
    // int numRecords = 0;
    // int gradeTotal = 0;
    // for (int recNum = 0; recNum < numRecords; recNum++) {
    //     studentRecord temp = sc.recordAt(recNum);
    //     numRecords++;
    //     gradeTotal += temp.grade();
    // }
    // // This is inefficient because the total node visit is
    // // equal to (1 + 2 + ... + numRecords) = (numRecords + 1)/2 * numRecords
    // // if length = 100, then we will visit node 5050 times!
    // double average = (double) gradeTotal / numRecords;
    // std::cout << average << std::endl;

    // // Example of list iterator
    // std::list<int> integerList = {10, 1, 20, 2, 30, 3};
    // std::list<int>::iterator iter;
    // iter = integerList.begin();
    // while (iter != integerList.end()) {
    //     std::cout << *iter << ' ';
    //     iter++;
    // }
    // std::cout << std::endl;

    scIterator iter;
    int gradeTotal = 0;
    int numRecords = 0;
    iter = sc.firstItemIterator();
    while (!iter.pastEnd()) {
        numRecords++;
        gradeTotal += iter.student().grade();
        iter.advance();
    }
    double average = (double) gradeTotal / numRecords;
    std::cout << average << std::endl;
}
