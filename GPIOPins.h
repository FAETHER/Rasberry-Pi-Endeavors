#ifndef HEADER_H
#define HEADER_H

#include "GPIOClass.h"
//#pragma once

struct pins
{
 	GPIOClass* gpio1 = new GPIOClass("1"); //BCM 1 (ID_SC) N28
    GPIOClass* gpio2 = new GPIOClass("2"); //BCM 2 (SDA)    N3
 	GPIOClass* gpio3 = new GPIOClass("3");    //BCM 3 (SCL)		N5
    GPIOClass* gpio4 = new GPIOClass("4");    //BCM 4 (GPcLK0) N7
 	GPIOClass* gpio5 = new GPIOClass("5");    //BCM 5  N29
    GPIOClass* gpio6 = new GPIOClass("6");    //BCM 6 N31
 	GPIOClass* gpio7 = new GPIOClass("7");    //BCM 7 (CE1) N26
    GPIOClass* gpio8 = new GPIOClass("8");	  //BCM 8 (CE0) N24
 	GPIOClass* gpio9 = new GPIOClass("9");    //BCM 9 (MISO) N21
    GPIOClass* gpio10 = new GPIOClass("10"); //BCM 10 (MOSI) N19
 	GPIOClass* gpio11 = new GPIOClass("11"); //BCM 11 (SCLK) N23
    GPIOClass* gpio12 = new GPIOClass("12"); //BCM 12 (PWM0) N28
 	GPIOClass* gpio13 = new GPIOClass("13"); //BCM 13 (PWM1) N33
    GPIOClass* gpio14 = new GPIOClass("14"); //BCM 14 (TXD) N8
 	GPIOClass* gpio15 = new GPIOClass("15"); //BCM 15 (RXD) N10
    GPIOClass* gpio16 = new GPIOClass("16"); //BCM 16 () N36
 	GPIOClass* gpio17 = new GPIOClass("17"); //BCM 17 () N11
    GPIOClass* gpio18 = new GPIOClass("18"); //BCM 18 (PWM0) N12
 	GPIOClass* gpio19 = new GPIOClass("19"); //BCM 19 (MISO) N35
    GPIOClass* gpio20 = new GPIOClass("20"); //BCM 20 (MOSI) N38
 	GPIOClass* gpio21 = new GPIOClass("21"); //BCM 21 (SCLK) N40
    GPIOClass* gpio22 = new GPIOClass("22"); //BCM 22 () N15
 	GPIOClass* gpio23 = new GPIOClass("23"); //BCM 23 () N16
    GPIOClass* gpio24 = new GPIOClass("24"); //BCM 24 () N18
 	GPIOClass* gpio25 = new GPIOClass("25"); //BCM 25 () N25
    GPIOClass* gpio26 = new GPIOClass("26"); //BCM 26 () N37
 	GPIOClass* gpio27 = new GPIOClass("27"); //BCM 27 () N13
//    GPIOClass* gpio28 = new GPIOClass("28"); 
// 	GPIOClass* gpio29 = new GPIOClass("29"); 
//    GPIOClass* gpio30 = new GPIOClass("30"); 
// 	GPIOClass* gpio31 = new GPIOClass("31"); 
//    GPIOClass* gpio32 = new GPIOClass("32"); 
// 	GPIOClass* gpio33 = new GPIOClass("33"); 
 //   GPIOClass* gpio34 = new GPIOClass("34"); 
// 	GPIOClass* gpio35 = new GPIOClass("35"); 
 //   GPIOClass* gpio36 = new GPIOClass("36"); 
 //	GPIOClass* gpio37 = new GPIOClass("37"); 
 //   GPIOClass* gpio38 = new GPIOClass("38"); 
 //	GPIOClass* gpio39 = new GPIOClass("39"); 
//    GPIOClass* gpio40 = new GPIOClass("40"); 	
	
	GPIOClass* arr_pins[27] =
	{
		gpio1,
		gpio2,
		gpio3,
		gpio4,
		gpio5,
		gpio6,
		gpio7,
		gpio8,
		gpio9,
		gpio10,
		gpio11,
		gpio12,
		gpio13,
		gpio14,
		gpio15,
		gpio16,
		gpio17,
		gpio18,
		gpio19,
		gpio20,
		gpio21,
		gpio22,
		gpio23,
		gpio24,
		gpio25,
		gpio26,
		gpio27,
//		gpio28,
//		gpio29,
//		gpio30,
//		gpio31,
//		gpio32,
//		gpio33,
//		gpio34,
//		gpio35,
//		gpio36,
//		gpio37,
//		gpio38,
//		gpio39,
//		gpio40,
	};	
	
} ;

#endif // HEADER_H