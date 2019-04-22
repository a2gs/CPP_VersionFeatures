/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * C++ 11 Thread Join and Detach samples (with synchronism (mutex) to cout).
 *
 * MIT License
 *
 */

/* thread1.cpp
 * C++ 11 Thread Join and Detach samples (with synchronism (mutex) to cout).
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *          |            |
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <iostream>
#include <sstream>
#include <cstdlib> /* C++17 has std::from_chars */
#include <thread>
#include <mutex>
#include <chrono>


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */
using namespace std;


/* *** LOCAL PROTOTYPES (if applicable) ************************************************ */


/* *** EXTERNS / LOCAL / GLOBALS VARIEBLES ********************************************* */
std::mutex glock;


/* *** FUNCTIONS *********************************************************************** */
/* <header function description ONLY for local functions (not in .h)> void function(void)
 *
 * <Description>
 *
 * INPUT:
 *  <None>
 * OUTPUT:
 *  <None>
 */

class PrintThread: public std::ostringstream
{
	public:
		PrintThread() = default;

		~PrintThread()
		{
			glock.lock();
			std::cout << this->str();
			glock.unlock();
		}
};

void func1(int seg)
{
	PrintThread () << "[De dentro da thread func1() " << this_thread::get_id() << "] ira demorar " << seg << " segundos para terminar." << endl;

	this_thread::sleep_for(chrono::seconds(seg));

	PrintThread () << "[De dentro da thread func1() " << this_thread::get_id() << "] terminou agora." << endl;
}

void func2(int seg)
{
	PrintThread () << "[De dentro da thread func2() " << this_thread::get_id() << "] ira demorar " << seg << " segundos para terminar." << endl;

	this_thread::sleep_for(chrono::seconds(seg));

	PrintThread () << "[De dentro da thread func2() " << this_thread::get_id() << "] terminou agora." << endl;
}

int main(int argc, char *argv[])
{
	if(argc != 4){
		cout << "Usage: " << argv[0] << " <SECONDS_FIRST_THREAD> <SECONDS_BETWEEN_THREADS> <SECONDS_SECOND_THREAD>" << endl;
		return(-1);
	}

	cout << "*Processo principal: " << this_thread::get_id() << endl << endl;

	/* t1 */
	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Vai dispar thread t1 com func1()." << endl;
   thread t1(func1, atoi(argv[1]));
	std::thread::id t1Id = t1.get_id();

	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Disparou t1 (func1(" << argv[1] << ")). Fazendo detach t1 (id = " << t1.get_id() << ")." << endl;
   t1.detach();

	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Thread t1 returnou para proc principal." << endl;

	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Aguardando " << argv[2] << " seg para lancar t2." << endl;
	this_thread::sleep_for(chrono::seconds(atoi(argv[2])));

	/* t2 */
	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Vai dispar thread t2 com func2()." << endl;
   thread t2(func2, atoi(argv[3]));
	std::thread::id t2Id = t2.get_id();

	if(t1Id == t2Id) // WRONG(because one of these threads may be terminated (thread::id of a non-executing thread)): if(t1.get_id() == t2.get_id())
		PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] DETALHE: t2 tem o mesmo Id de t1 pois este foi liberado antes e o Id eh reutilizado!" << endl;

	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Disparou t2 (func2(" << argv[3] << ")). Fazendo join t2 (id = " << t2.get_id() << ")." << endl;
   t2.join();
	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] Thread t2 returnou para proc principal." << endl;

	PrintThread () << "[*De dentro do processo principal " << this_thread::get_id() << "] FIM." << endl;
   return(0);
}
