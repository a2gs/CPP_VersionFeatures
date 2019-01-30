#include <iostream>

using namespace std;

class singleton
{
	public:
		static singleton & instance()
		{
			static singleton inst;
			return(inst);
		}

		int x;

		/* Scott Meyers, Effective C++ (42), 7rel, chap 3 item 11 */
		singleton(singleton const &) = delete;
		singleton operator=(singleton const &) = delete;

	private:
		singleton(){
			cout << "Singleton constructor" << endl;
		}

		~singleton()
		{
			cout << "Singleton destructor" << endl;
		}
};

int main(int argc, char *argv[])
{
	singleton *var1 = &singleton::instance();
	singleton *var2 = &singleton::instance();
	singleton *var3 = &singleton::instance();

	var1->x = 10;

	cout << var2->x << endl;

	var3->x = 8;
	cout << var2->x << endl;

	return(0);
}
