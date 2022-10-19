CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
OBJS := llrec-test.o llrec.o
STACKOBJS := stack-test.o stack.o

all: llrec-test stack-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
stack-test: $(STACKOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(STACKOBJS)

llrec-test.o: llrec-test.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp
stack.o: stack.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ -c stack.cpp
stack-test.o: stack-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c stack-test.cpp

valgrind:
	$(VALGRIND) ./llrec-test


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 