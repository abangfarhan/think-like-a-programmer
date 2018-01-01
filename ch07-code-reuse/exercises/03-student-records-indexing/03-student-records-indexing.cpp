#include <iostream>
#include <algorithm>
#include "01-student-record-class.h"

int compareStudentRecord(const void * voidA, const void * voidB) {
    studentRecord * studentA = (studentRecord *) voidA;
    studentRecord * studentB = (studentRecord *) voidB;
    return studentA->grade() - studentB->grade();
}

bool compareStudentRecord2(studentRecord studentA, studentRecord studentB) {
    return studentA.studentID() < studentB.studentID();
}

studentRecord getByStudentNum(studentRecord records[], int arraySize, int studentNum) {
    studentRecord copiedRecords[arraySize];
    for (int i = 0; i < arraySize; i++)
        copiedRecords[i] = records[i];
    // qsort(copiedRecords, arraySize, sizeof(studentRecord), compareStudentRecord);
    std::sort(copiedRecords, (copiedRecords+arraySize), compareStudentRecord2);

    // Interpolation Search
    int low = 0;
    int high = arraySize - 1;
    int mid;
    while ((copiedRecords[high].studentID() != copiedRecords[low].studentID()) &&
           (studentNum >= copiedRecords[low].studentID()) &&
           (studentNum <= copiedRecords[high].studentID()))
    {
        mid = low + ((studentNum - copiedRecords[low].studentID()) * (high - low) / (copiedRecords[high].studentID() - copiedRecords[low].studentID()));
        if (studentNum > copiedRecords[mid].studentID())
            low = mid + 1;
        else if (studentNum < copiedRecords[mid].studentID())
            high = mid - 1;
        else
            break;
    }

    if (studentNum >= copiedRecords[0].studentID() &&
            studentNum <= copiedRecords[arraySize-1].studentID() &&
            studentNum == copiedRecords[mid].studentID())
        return copiedRecords[mid];
    else {
        studentRecord dummyRecord;
        return dummyRecord;
    }
}

int main() {
    studentRecord s1(95, 1003, "Mike");
    studentRecord s2(91, 1001, "Abdul");
    studentRecord s3(93, 1002, "Steve");
    const int arraySize = 3;
    studentRecord records[arraySize];
    records[0] = s1;
    records[1] = s2;
    records[2] = s3;

    studentRecord target = getByStudentNum(records, arraySize, 1000);
    target.showStudentProperties();
}
