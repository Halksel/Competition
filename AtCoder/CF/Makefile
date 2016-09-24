CXXFLAGS = -g -std=c++14 -fdiagnostics-color=always -Wall -Wextra -ftrapv

SRC=
OBJ=$(SRC:.cpp=.o)
PROG=$(SRC:.cpp=.out)

CXX = g++
$(PROG):$(OBJ)
		$(CXX) -o $@ $<

.PHONY : clean
clean:
	rm -rf *.o *.out .*
