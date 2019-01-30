all: clean thread1 singleton

CPP_ARGS = -g -Wall -std=c++11

thread1:
	g++ -o thread1 thread1.cpp -lpthread $(CPP_ARGS)

singleton:
	g++ -o singleton singleton.cpp $(CPP_ARGS)


clean:
	-rm thread1 singleton
