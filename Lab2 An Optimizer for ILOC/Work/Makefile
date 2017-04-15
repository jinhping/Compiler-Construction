
	
GCC = g++
CFLAGS = -std=c++11 -Wall -g

iloc: iloc.o iloc.o code.o
	$(GCC) iloc.o iloc.tab.o code.o -o iloc
	
iloc.o: iloc.cc iloc.l 
	$(GCC) $(CFLAGS) -c iloc.cc

iloc.tab.o: iloc.cc  iloc.y
	$(GCC) $(CFLAGS) -c iloc.tab.cc 
	
iloc.cc: iloc.l iloc.tab.cc 
	flex -o iloc.cc  iloc.l
	
iloc.tab.cc : iloc.y
	bison -o iloc.tab.cc  -d iloc.y
	
code.o: code.cc code.h
	$(GCC) $(CFLAGS) -c code.cc
	
clean: 
	rm -f iloc *.o iloc.cc *.tab.cc *.tab.hh