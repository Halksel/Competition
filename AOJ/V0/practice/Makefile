CPPFLAGS = -g -std=c++11 -Wall -Wextra

SRC=
OBJ=$(SRC:.cpp=.o)
PROG=$(SRC:.cpp=)

CPP=g++
$(PROG):$(OBJ)
		$(CPP) -o $@ $<

.PHONY : clean
clean:
	rm -rf .*
