#include <iostream>

using namespace std;

class AAA
{
	private:
		int x;
	public:
		AAA()
		{
			cout << "\tConstrutor padrao AAA" << endl;
		};
		AAA(int a) : x(a)
		{
			cout << "\tConstrutor AAA" << endl;
		};
};

class BBB : public AAA
{
	private:
		int x;
	public:
		BBB()
		{
			cout << "\tConstrutor padrao BBB" << endl;
		};
		BBB(int a) : x(a)
		{
			cout << "\tConstrutor BBB" << endl;
		};
};

int main(int argc, char *argv[])
{
	cout << "Criando objeto AAA test1:" << endl;
	AAA test1;

	cout << "Criando objeto BBB test2:" << endl;
	BBB test2;

	cout << "------------------------" << endl;

	cout << "Criando objeto AAA test3:" << endl;
	AAA test3(1);

	cout << "Criando objeto BBB test4:" << endl;
	BBB test4(2);

	return(0);
}
