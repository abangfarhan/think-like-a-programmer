CXX = g++
CXXFLAGS = --std=c++11

01-first-student: 01-first-student.o 01-student-collection.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 01-first-student 01-first-student.o 01-student-collection.o 01-student-record-class.o

01-first-student.o: 01-first-student.cpp ../ch05-classes/01-student-record-class.h 01-student-collection.h
	$(CXX) $(CXXFLAGS) -c 01-first-student.cpp

01-student-collection.o: 01-student-collection.cpp 01-student-collection.h
	$(CXX) $(CXXFLAGS) -c 01-student-collection.cpp

01-student-record-class.o: ../ch05-classes/01-student-record-class.cpp ../ch05-classes/01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c ../ch05-classes/01-student-record-class.cpp

02-student-traversal: 02-student-traversal.o 02-scIterator.o 01-student-collection.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 02-student-traversal 02-student-traversal.o 02-scIterator.o 01-student-collection.o 01-student-record-class.o

02-student-traversal.o: 02-student-traversal.cpp ../ch05-classes/01-student-record-class.h 01-student-collection.h 02-scIterator.h
	$(CXX) $(CXXFLAGS) -c 02-student-traversal.cpp

02-scIterator.o: 02-scIterator.cpp 02-scIterator.h 01-student-collection.h ../ch05-classes/01-student-record-class.h 01-student-collection.h
	$(CXX) $(CXXFLAGS) -c 02-scIterator.cpp
