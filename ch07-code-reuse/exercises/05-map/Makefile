CXX = g++
CXXFLAGS = --std=c++11 -g

05-map: 05-map.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 05-map 05-map.o 01-student-record-class.o

05-map.o: 05-map.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 05-map.cpp

01-student-record-class.o: 01-student-record-class.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record-class.cpp
