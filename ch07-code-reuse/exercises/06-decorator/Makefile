CXX = g++
CXXFLAGS = --std=c++11 -g

06-decorator: 06-decorator.o 06-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 06-decorator 06-decorator.o 06-student-record-class.o

06-decorator.o: 06-decorator.cpp 06-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 06-decorator.cpp

06-student-record-class.o: 06-student-record-class.cpp 06-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 06-student-record-class.cpp
