CPP = g++
CPPFLAGS = -g -Wall -D_XOPEN_SOURCE=700

RM = rm -f

all: clean inheritance virtual constructorSequence singleton

inheritance:
	$(CPP) -o inheritance inheritance.cpp $(CPPFLAGS)

virtual:
	$(CPP) -o virtual virtual.cpp $(CPPFLAGS)

constructorSequence:
	$(CPP) -o constructorSequence constructorSequence.cpp $(CPPFLAGS)

singleton:
	$(CPP) -o singleton singleton.cpp $(CPPFLAGS)

clean:
	-$(RM) inheritance virtual constructorSequence singleton
