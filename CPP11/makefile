CPP = g++
CPPFLAGS = -g -Wall -std=c++11 -D_XOPEN_SOURCE=700

RM = rm -f

all: clean thread1 singleton

thread1:
	$(CPP) -o thread1 thread1.cpp -lpthread $(CPPFLAGS)

singleton:
	$(CPP) -o singleton singleton.cpp $(CPPFLAGS)

clean:
	-$(RM) thread1 singleton
