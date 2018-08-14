#include "GPIOClass.h"
#include "GPIOPins.h"
//#include "Utils.h"
#include "LEDStrip.h"
#include <rpi_ws281x/ws2811.h>

ws2811_led_t dotcolors[] =
{
	0x00200000,  // red
	0x00201000,  // orange
	0x00202000,  // yellow
	0x00002000,  // green
	0x00002020,  // lightblue
	0x00000020,  // blue
	0x00100010,  // purple
	0x00200010,  // pink
};

ws2811_channel_t channel0 = {GPIO_PIN,0,LED_COUNT,STRIP_TYPE,dotcolors,150};

ws2811_t ledstring = {5,0,0,TARGET_FREQ,DMA,channel0,};


bool LEDStrip::init_led()
{	
	ws2811_init(&ledstring);
	return true;
}

int LEDStrip::test_()
{
	ws2811_init(&ledstring);
	
	if (ledstring.channel[0].strip_type == STRIP_TYPE)
	{
		for(int i =0; i<sizeof(dotcolors)/sizeof(int); i++)
		{
			ledstring.channel[0].leds[1] = dotcolors[i];
			usleep(1000000);
			ws2811_render(&ledstring);
		}
	}
	return 1;
}

int LEDStrip::led_strip_on()
{
    int c = 0;

    for (int i = 0; i <LED_COUNT; i++)
    {
        if (c == sizeof(dotcolors)/sizeof(int))
        {
            c = 0;
        }

        if (ledstring.channel[0].strip_type == STRIP_TYPE) {
            ledstring.channel[0].leds[i] = dotcolors[c];
        }
	
        c++;

        ws2811_render(&ledstring);

        usleep(100000);
	
    }
	return 1;
}

int LEDStrip::led_strip_on_back(int delay)
{
    int c = 0;

    for (int i = LED_COUNT; i >-1; i--)
    {
        if (c == sizeof(dotcolors)/sizeof(int))
        {
            c = 0;
        }

        if (ledstring.channel[0].strip_type == STRIP_TYPE) {
            ledstring.channel[0].leds[i] = dotcolors[c];
        }
	
        c++;

        ws2811_render(&ledstring);

        usleep(delay);
	
    }
}

int LEDStrip::led_strip_off(int delay)
{
    for (int i = 0; i < LED_COUNT; i++)
    {
        if (ledstring.channel[0].strip_type == STRIP_TYPE) {
            ledstring.channel[0].leds[i] = 0x00000000;
        }
        ws2811_render(&ledstring);
        usleep(delay);
    }
	return 1;
}

int LEDStrip::led_strip_off_back(int delay)
{
    for (int i = LED_COUNT; i > -1; i--)
    {
        if (ledstring.channel[0].strip_type == STRIP_TYPE) {
            ledstring.channel[0].leds[i] = 0x00000000;
        }
        ws2811_render(&ledstring);
        usleep(delay);
    }
	return 1;
}