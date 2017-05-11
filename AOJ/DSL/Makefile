CPPFLAGS = -g -std=c++11 -fdiagnostics-color=always -Wall -Wextra -ftrapv -O2

SRC=
OBJ=$(SRC:.cpp=.o)
PROG=$(SRC:.cpp=.out)

CXX=g++
$(PROG):$(OBJ)
		$(CXX) -o $@ $<

.PHONY : clean
clean:
	rm -rf *.o .* *.out
