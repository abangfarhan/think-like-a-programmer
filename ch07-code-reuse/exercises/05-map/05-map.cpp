#include <iostream>
#include <map>
#include "01-student-record-class.h"

int main() {
    std::map<int, studentRecord> records;
    records[1003] = studentRecord(95, 1003, "Mike");
    records[1001] = studentRecord(91, 1001, "Abdul");
    records[1002] = studentRecord(93, 1002, "Steve");

    // method 1
    records[1003].showStudentProperties();
    records[1001].showStudentProperties();
    records[1002].showStudentProperties();

    // method 2
    // see https://www.moderncplusplus.com/map/
    for (auto& s: records) {
        s.second.showStudentProperties();
    }

    // method 3
    for (std::map<int, studentRecord>::value_type& s: records) {
        s.second.showStudentProperties();
    }
}
