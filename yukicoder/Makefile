CPPFLAGS = -g -std=c++11 -fdiagnostics-color=always -Wall -Wextra -I/Users/Hira/local/include/

SRC=
OBJ=$(SRC:.cpp=.o)
PROG=$(SRC:.cpp=.out)

CPP=g++-mp-4.9
$(PROG):$(OBJ)
		$(CPP) -o $@ $<

.PHONY : clean
clean:
	rm -rf *.o .*
