
#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

#define NO_EDGE      0
#define RISING_EDGE  1
#define FALLING_EDGE 2
#define BOTH_EDGE    3

using namespace std;
/* GPIO Class
 * Purpose: Each object instatiated from this class will control a GPIO pin
 * The GPIO pin number must be passed to the overloaded class constructor
 */
class GPIOClass
{
public:
	GPIOClass();
	GPIOClass(string gnum);
	~GPIOClass();
    int setdir_gpio(string dir);
    int setval_gpio(string val);
    int getval_gpio(string& val);
    string get_gpionum();
	string retval_gpio();
	
	//edge detection
	int add_edge_detect(unsigned int edge);
	//void remove_edge_detect(unsigned int gpio);
	//int add_edge_callback(unsigned int gpio, void (*func)(unsigned int gpio));
	//int event_detected(unsigned int gpio);
	//int gpio_event_added(unsigned int gpio);
	//int event_initialise(void);
	//void event_cleanup(void);
	//int blocking_wait_for_edge(unsigned int gpio, unsigned int edge);

private:
    int export_gpio();
	int unexport_gpio();
	int gpio_set_edge(string gpio, unsigned int edge);
	
	int valuefd;
	int directionfd;
	int exportfd;
	int unexportfd;
	string gpionum;
	const char *stredge[4] = {"none", "rising", "falling", "both"};
};

#endif
