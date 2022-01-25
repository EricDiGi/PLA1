CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.h)
OBJECTS = $(SRCS: .h=.o)

all: basic

basic: $(OBJECTS) main.c Lexer.h Parse.h
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main