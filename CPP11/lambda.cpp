/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 0;

	auto lambda1 = [](const char *s){
		cout << s << endl;
		return(13);
	};

	i = lambda1("lambda");

	cout << "-----------------------" << endl;

	float f1 = 0.0;
	int a1 = 10;
	int b1 = 20;

	auto lambda2a = [a1, &b1]() -> float{
		// ++a1; ---> 'a1' is readonly
		b1 = 20;
		cout << "lambda2a: a1 = [" << a1 << "] b1 = [" << b1 << "]" << endl;
		return 13.8;
	};

	f1 = lambda2a();

	cout << "main: a1 = [" << a1 << "] b1 = [" << b1 << "] f1 = [" << f1 << "]" << endl << endl;

	/* --- [=] --- */

	float f2 = 0.0;
	int a2 = 10;
	int b2 = 20;

	auto lambda2b = [=]() -> float{
		// ++a2; ---> 'a2' is readonly
		// b2 = 20; ---> 'b2' is readonly
		cout << "lambda2b [=]: a2 = [" << a2 << "] b2 = [" << b2 << "]" << endl;
		return 13.8;
	};

	f2 = lambda2b();

	cout << "main: a2 = [" << a2 << "] b2 = [" << b2 << "] f2 = [" << f2 << "]" << endl << endl;

	/* --- [&] --- */
	float f3 = 0.0;
	int a3 = 10;
	int b3 = 20;

	auto lambda2c = [&]() -> float{
		++a3;
		b3 = 200;
		cout << "lambda2c [&]: a3 = [" << a3 << "] b3 = [" << b3 << "]" << endl;
		return 13.8;
	};

	f3 = lambda2c();

	cout << "main: a3 = [" << a3 << "] b3 = [" << b3 << "] f3 = [" << f3 << "]" << endl;

	cout << "-----------------------" << endl;

	auto n = [] (int x, int y) -> int { return x + y; }(5, i);
	std::cout << n << '\n';

	cout << "-----------------------" << endl;

	vector<int> test = {2, 3, 4, 5, 6, 7, 8, 9};
	auto print = [](const int& n) { std::cout << " " << n; };

	test.erase(remove_if(test.begin(),
	                     test.end(),
	                     [](int x) -> bool{
									return(x % 2);
	                     }),
	           test.end());

	for_each(test.begin(), test.end(), print);

	cout << endl;

	return(0);
}
