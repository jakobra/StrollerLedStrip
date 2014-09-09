#include "PololuLedStrip.h"

#ifndef LED_PRINTER_H
#define LED_PRINTER_H

#define LED_COUNT 22

class LedPrinter {
	public:
		rgb_color Colors[LED_COUNT];
		LedPrinter() {};
		void Print();
};

#endif