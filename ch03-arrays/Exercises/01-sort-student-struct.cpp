#include <iostream>
#include <string>

struct student {
    int grade;
    int studentID;
    std::string name;
};

int compareGrade(const void* voidA, const void* voidB){
    student* studentA = (student*)(voidA);
    student* studentB = (student*)(voidB);
    return studentA->grade - studentB->grade;
}

int compareID(const void* voidA, const void* voidB){
    student* studentA = (student*)(voidA);
    student* studentB = (student*)(voidB);
    return studentA->studentID - studentB->studentID;
}

int main(){
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    std::cout << "Original Data" << std::endl;
    for(int i=0; i<ARRAY_SIZE; i++){
        std::cout << studentArray[i].grade << ' ' << studentArray[i].studentID << ' ' << studentArray[i].name << std::endl;
    }

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrade);
    std::cout << "Sorted Data (by grade)" << std::endl;
    for(int i=0; i<ARRAY_SIZE; i++){
        std::cout << studentArray[i].grade << ' ' << studentArray[i].studentID << ' ' << studentArray[i].name << std::endl;
    }

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareID);
    std::cout << "Sorted Data (by ID)" << std::endl;
    for(int i=0; i<ARRAY_SIZE; i++){
        std::cout << studentArray[i].grade << ' ' << studentArray[i].studentID << ' ' << studentArray[i].name << std::endl;
    }
}
