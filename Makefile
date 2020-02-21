all: main.o functions.o
	g++ main.o functions.o -o run_test
main.o: main.cpp f_lib.hpp
	g++ -c main.cpp
functions.o: functions.cpp f_lib.hpp
	g++ -c functions.cpp

clean:
	rm *.o
	rm run_test
