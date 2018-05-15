testlist: testlist.o list.o
	g++ -g $^ -o $@

list.o: list.cpp list.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testlist.o: testlist.cpp list.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm list.o testlist.o testlist