#include "GPIOClass.h"
#include "GPIOPins.h"
#include "LEDStrip.h"
#include "Utils.h"
#include <rpi_ws281x/ws2811.h>
#include <cstdint>
#include <string> 
#include <vector>
#include <stdio.h>

using namespace std;

void Setup(pins pin)
{
	cout << "Gpio pins exported" <<endl;
	pin.gpio17->setdir_gpio("in");
	pin.gpio4->setdir_gpio("out");
	//pin.gpio3->setdir_gpio("in");
	pin.gpio3->add_edge_detect(1);
	cout << "Set GPIO pin directions" <<endl;
}

void led_basic(pins pin)
{
	LEDStrip strip;	
	Utils obj;
	string inputstate;
	int i = 0;
	
    while(i<40)
    {
        usleep(500000);  
        pin.gpio17->getval_gpio(inputstate); 
        cout << "Current input pin state is " << inputstate  <<endl;
        if(inputstate == "0") 
        {
            cout << "input pin state is \"Pressed \".n Will check input pin state again in 20ms "<<endl;
                usleep(20000);
                    cout << "Checking again ....." << endl;
               		pin.gpio17->getval_gpio(inputstate); 

            if(inputstate == "0")
            {
                cout << "input pin state is definitely \"Pressed\". Turning LED ON" <<endl;
                pin.gpio4->setval_gpio("1"); 
 		
		
    			strip.init_led();
				for(int i=0; i<10; i++)
				{
					strip.led_strip_on();
					strip.led_strip_off(100000);
					strip.led_strip_on_back(100000);
					strip.led_strip_off_back(100000);
					obj.safe_exit(pin);
				}
                cout << " Waiting until pin is unpressed....." << endl;
                while (inputstate == "0"){
                pin.gpio17->getval_gpio(inputstate);
                };
                cout << "pin is unpressed" << endl;
 
            }
            else
                cout << "input pin state is definitely \"UnPressed\". That was just noise." <<endl;
 
        }
        pin.gpio4->setval_gpio("0");
        i++;
		obj.safe_exit(pin);
    }	
    obj.del_gpio(pin);
}

void PIR (pins pin)
{
	cout<<pin.gpio3->retval_gpio()<<endl;
	for(int i=0;i<1000; i++)
	{
		usleep(20000);
		if(pin.gpio3->retval_gpio().compare("0") == 0)
		   {
			 	cout<<"ya"<<endl;  
		   }
		   else
		   {
			 	cout<<"nah"<<endl;  
		   }
	}
}

int main (void)
{
	Utils obj;
	pins pin;
	Setup(pin);
	
	obj.init_signal();
	
	//led_basic(pin);
	PIR(pin);

		
    obj.del_gpio(pin);
    return 0;
}
