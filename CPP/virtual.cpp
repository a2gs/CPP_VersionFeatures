#include <iostream>

using namespace std;

class Base
{
	public:
		Base()
		{
			cout << "Base: Constructor" << endl;
		}

		void nonVirtualFunc()
		{
			cout << "Base: non-virtual function" << endl;
		}

		virtual void virtualFunc()
		{
			cout << "Base: virtual function" << endl;
		}

		virtual void pureVirtualFunc() = 0;

		virtual ~Base(){}; // BASE CLASES MUST HAVE virtual (not pure =0) DESTRUCTORS
};

class Child : public Base
{
	public:
		Child()
		{
			cout << "Child: Constructor" << endl;
		}

		void nonVirtualFunc()
		{
			cout << "Child: non-virtual function" << endl;
		}

		void virtualFunc()
		{
			cout << "Child: virtual function" << endl;
		}

		virtual void pureVirtualFunc()
		{
			cout << "Child: PURE virtual function" << endl;
		}
		~Child()
		{
			cout << "Child: Destructor" << endl;
		};
};              

int main()
{
	Base *basePointer = new Child();

	basePointer->nonVirtualFunc();
	basePointer->virtualFunc();
	basePointer->pureVirtualFunc();

	delete basePointer;

	return(0);
}
