CXX = g++
CXXFLAGS = --std=c++11 -g

03-student-records-indexing: 03-student-records-indexing.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 03-student-records-indexing 03-student-records-indexing.o 01-student-record-class.o

03-student-records-indexing.o: 03-student-records-indexing.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 03-student-records-indexing.cpp

01-student-record-class.o: 01-student-record-class.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record-class.cpp
