all: hw4
hw2: main.o openHashTable.o chainHashTable.o 
	g++ main.o openHashTable.o chainHashTable.o  -o hw4
main.o: main.cpp
	g++ -c main.cpp

openHashTable.o: openHashTable.cpp openHashTable.h
	g++ -c openHashTable.cpp openHashTable.h

chainHashTable.o: chainHashTable.cpp chainHashTable.h
	g++ -c chainHashTable.cpp chainHashTable.h



clean:
	rm *o hw4 *h.gch