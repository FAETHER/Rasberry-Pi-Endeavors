#include "GPIOClass.h"
#include "GPIOPins.h"
#include <signal.h>

class Utils
{
	public:
	void del_gpio(pins pin);
	void safe_exit(pins pin);
	void init_signal(); 
	
	private:
	
	//void sig_handler(int sig);
};
