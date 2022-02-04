CXX = gcc
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.h)
OBJECTS = $(SRCS: .h=.o)

all: basic

compile: $(OBJECTS) main.c common.h parse.h table.h lex.h
	$(CXX) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main
