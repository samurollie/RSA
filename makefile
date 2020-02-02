SRC := numbers/numbers.h
INC := numbers/numbers.cpp

compile:
	g++ $(SRC) $(INC) main.cpp -o main