CXX = g++
CXXFLAGS = --std=c++11

03-class-strings: 03-class-strings.o 03-MyString.o
	$(CXX) $(CXXFLAGS) -o 03-class-strings 03-class-strings.o 03-MyString.o

03-class-strings.o: 03-class-strings.cpp 03-MyString.h
	$(CXX) $(CXXFLAGS) -c 03-class-strings.cpp

03-MyString.o: 03-MyString.cpp 03-MyString.h
	$(CXX) $(CXXFLAGS) -c 03-MyString.cpp

clean:
	\rm *.o
