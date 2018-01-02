CXX = g++
CXXFLAGS = --std=c++11 -g

04-hash-table: 04-hash-table.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 04-hash-table 04-hash-table.o 01-student-record-class.o

04-hash-table.o: 04-hash-table.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 04-hash-table.cpp

01-student-record-class.o: 01-student-record-class.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record-class.cpp
