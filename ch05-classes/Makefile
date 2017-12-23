CXX = g++
CXXFLAGS = -std=c++11

01-student-record: 01-student-record.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 01-student-record 01-student-record.o 01-student-record-class.o

01-student-record.o: 01-student-record.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record.cpp

01-student-record-class.o: 01-student-record-class.cpp 01-student-record-class.h
	$(CXX) $(CXXFLAGS) -c 01-student-record-class.cpp

02-dynamic-student-record: 02-dynamic-student-record.o 02-student-collection.o 01-student-record-class.o
	$(CXX) $(CXXFLAGS) -o 02-dynamic-student-record 02-dynamic-student-record.o 02-student-collection.o 01-student-record-class.o

02-dynamic-student-record.o: 02-dynamic-student-record.cpp 02-student-collection.h
	$(CXX) $(CXXFLAGS) -c 02-dynamic-student-record.cpp

02-student-collection.o: 02-student-collection.cpp 02-student-collection.h
	$(CXX) $(CXXFLAGS) -c 02-student-collection.cpp

clean:
	\rm *.o
