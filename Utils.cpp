#include "GPIOPins.h"
#include "Utils.h"
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

bool ctrl_c_pressed = false;
void sig_handler(int sig)
{
    write(0,"nCtrl^C pressed in sig handlern/n",32);
    ctrl_c_pressed = true;
}

void Utils::init_signal()
{
	struct sigaction sig_struct;
    sig_struct.sa_handler = sig_handler;
    sig_struct.sa_flags = 0;
    sigemptyset(&sig_struct.sa_mask);

    if (sigaction(SIGINT, &sig_struct, NULL) == -1) {
        cout << "Problem with sigaction" << endl;
        exit(1);
    }	
}

void Utils::del_gpio(pins pin)
{
	cout<<"Cleaning up the memory...."<<sizeof(pins)<<"..."<<sizeof(pin.arr_pins[0])<<endl;
	for	(int i=0; i<sizeof(pins)/sizeof(pin.arr_pins[0])/2; i++ )
	{
		delete pin.arr_pins[i];
		pin.arr_pins[i] = 0;
	}
}

void Utils::safe_exit(pins pin)
{
	if(ctrl_c_pressed)
	{
		del_gpio(pin);
		exit(0);
	}
}
