CPP = g++
CPPFLAGS = -g -Wall -std=c++11 -D_XOPEN_SOURCE=700

RM = rm -f

all: clean thread1 finalOverride singleton lambda

thread1:
	@echo "=== thread1 =================================================="
	$(CPP) -o thread1 thread1.cpp -lpthread $(CPPFLAGS)

singleton:
	@echo "=== singleton ================================================"
	$(CPP) -o singleton singleton.cpp $(CPPFLAGS)

finalOverride:
	@echo "=== finalOverride (COMPILATION MUST RETURN ERROR) ============"
	-$(CPP) -o finalOverride finalOverride.cpp $(CPPFLAGS)

lambda:
	@echo "=== lambda ============================================"
	-$(CPP) -o lambda lambda.cpp $(CPPFLAGS)

clean:
	-$(RM) thread1 singleton finalOverride lambda
