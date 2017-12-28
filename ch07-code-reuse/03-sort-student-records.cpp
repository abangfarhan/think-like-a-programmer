#include <iostream>
#include "../ch05-classes/01-student-record-class.h"

int compareStudentRecord(const void * voidA, const void * voidB) {
    studentRecord * studentA = (studentRecord *) voidA;
    studentRecord * studentB = (studentRecord *) voidB;
    return studentA->grade() - studentB->grade();
}

int main() {
    // We will use 0 instead of -1
    // Because at the class definition we have defined
    // -1 as Invalid
    studentRecord s0(94, 1001, "Luthfi");
    studentRecord s1(90, 1002, "Alya");
    studentRecord s2(0, 1003, "Abang");
    studentRecord s3(95, 1004, "Faradisi");
    studentRecord s4(98, 1005, "Zakia");
    studentRecord s5(91, 1006, "Farhan");

    int arraySize = 6;
    studentRecord records[arraySize];
    records[0] = s0;
    records[1] = s1;
    records[2] = s2;
    records[3] = s3;
    records[4] = s4;
    records[5] = s5;
    
    for (int i = 0; i < arraySize; i++)
        printf("%d \n", records[i].grade());
    printf("\n");

    // insertion sort based on grade
    // int start = 0;
    // int end = arraySize - 1;
    // for (int i = start+1; i <= end; i++) {
    //     for (int j = i; j > start && records[j-1].grade() > records[j].grade(); j--) {
    //         studentRecord temp = records[j-1];
    //         records[j-1] = records[j];
    //         records[j] = temp;
    //     }
    // }

    // for (int i = 0; i < arraySize; i++)
    //     printf("%d \n", records[i].grade());

    // insertion sort, ignoring 0-grades
    // int start = 0;
    // int end = arraySize - 1;
    // for (int i = start+1; i <= end; i++)
    // {
    //     if (records[i].grade() != 0)
    //     {
    //         int rightSwap = i;
    //         for (int leftSwap = i-1;
    //                 leftSwap >= start &&
    //                 (records[leftSwap].grade() > records[rightSwap].grade() ||
    //                 records[leftSwap].grade() == 0);
    //                 leftSwap--)
    //         {
    //             if (records[leftSwap].grade() != 0)
    //             {
    //                 studentRecord temp = records[leftSwap];
    //                 records[leftSwap] = records[rightSwap];
    //                 records[rightSwap] = temp;
    //                 rightSwap = leftSwap;
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i < arraySize; i++)
    //     printf("%d \n", records[i].grade());
    // printf("\n");

    // using qsort
    studentRecord sortArray[arraySize];
    int arrayCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (records[i].grade() != 0) {
            sortArray[arrayCount] = records[i];
            arrayCount++;
        }
    }
    qsort(sortArray, arrayCount, sizeof(studentRecord), compareStudentRecord);

    arrayCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (records[i].grade() != 0) {
            records[i] = sortArray[arrayCount];
            arrayCount++;
        }
    }

    for (int i = 0; i < arraySize; i++)
        printf("%d \n", records[i].grade());
    printf("\n");
}
