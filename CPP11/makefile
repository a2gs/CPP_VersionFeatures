CPP = g++
CPPFLAGS = -g -Wall -std=c++11 -D_XOPEN_SOURCE=700

RM = rm -f

all: clean thread1 finalOverride singleton

thread1:
	@echo "\n=== thread1 =================================================="
	$(CPP) -o thread1 thread1.cpp -lpthread $(CPPFLAGS)

singleton:
	@echo "\n=== singleton ================================================"
	$(CPP) -o singleton singleton.cpp $(CPPFLAGS)

finalOverride:
	@echo "\n=== finalOverride (COMPILATION MUST RETURN ERROR) ============"
	-$(CPP) -o finalOverride finalOverride.cpp $(CPPFLAGS)

clean:
	-$(RM) thread1 singleton finalOverride
