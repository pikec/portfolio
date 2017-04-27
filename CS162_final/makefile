CXX=g++
CXXFLAGS= -g -Wall  
BIN=game

SRC=${wildcard *.cpp}
OBJ=${SRC:%.cpp=%.o}

all:: $(OBJ)
	${CXX} ${CXXFLAGS} -o ${BIN} $^

%.o: %.c
	${CXX} $@ -c $<

clean:
	rm -f *.o
	rm  ${BIN}
