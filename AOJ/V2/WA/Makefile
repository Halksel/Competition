CPPFLAGS = -g -std=c++11 -fdiagnostics-color=always -Wall -Wextra

SRC=
OBJ=$(SRC:.cpp=.o)
PROG=$(SRC:.cpp=.out)

CPP=g++
$(PROG):$(OBJ)
		$(CPP) -o $@ $<

.PHONY : clean
clean:
	rm -rf *.o .* *.out
