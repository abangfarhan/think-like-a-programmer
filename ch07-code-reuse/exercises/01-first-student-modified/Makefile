CXX = g++
CXXFLAGS = --std=c++11

01-first-student: 01-first-student.o 01-student-collection.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 01-first-student 01-first-student.o 01-student-collection.o 01-student-record-class.o

01-first-student.o: 01-first-student.cpp 01-student-record-class.h 01-student-collection.h
	$(CXX) $(CXXFLAGS) -c 01-first-student.cpp

01-student-collection.o: 01-student-collection.cpp 01-student-collection.h
	$(CXX) $(CXXFLAGS) -c 01-student-collection.cpp

01-student-record-class.o: 01-student-record-class.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record-class.cpp
