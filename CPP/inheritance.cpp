#include <iostream>

using namespace std;

class AAA
{
	protected:
		AAA(){
			cout << "AAA Constructor." << endl;
		};

	private:
		int x;

	protected:
		int y;

	public:

		int z;

		virtual ~AAA(){ // BASE CLASES MUST HAVE virtual DESTRUCTORS
			cout << "AAA Destructor." << endl;
		};
};

class BBB : public AAA
{
	private:
		int x;

	protected:
		int y;

	public:
		int z;

		BBB(){
			cout << "BBB Constructor." << endl;
		};
		~BBB(){
			cout << "BBB Destructor." << endl;
		};
};

class CCC : public AAA
{
	private:
		int x;

	protected:
		int y;

	public:
		int z;

		CCC(){
			cout << "CCC Constructor." << endl;
		};
		~CCC(){
			cout << "CCC Destructor." << endl;
		};
};

int main(int argc, char *argv[])
{
	AAA *var;

	var = new BBB();
	delete var;

	var = new CCC();
	delete var;

	return(0);
}
