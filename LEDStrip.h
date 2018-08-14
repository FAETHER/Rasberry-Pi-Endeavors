#include "GPIOClass.h"
#include "GPIOPins.h"
//#include "Utils.h"
#include <rpi_ws281x/ws2811.h>


#define TARGET_FREQ                             WS2811_TARGET_FREQ
#define GPIO_PIN                                18
#define DMA                                           5
#define STRIP_TYPE                              WS2811_STRIP_RGB        // WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE                            WS2811_STRIP_GBR        // WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE                            SK6812_STRIP_RGBW       // SK6812RGBW (NOT SK6812RGB)
#define LED_COUNT                               20

class LEDStrip
{
	public:
	bool init_led();
	int test_();
	int led_strip_on();
	int led_strip_on_back(int delay);
	int led_strip_off(int delay);
	int led_strip_off_back(int delay);
	
	private:
};