#include "LedStripColors.h"

#ifndef LED_PRINTER_H
#define LED_PRINTER_H

class LedPrinter {
	public:
		LedPrinter() {};
		void Print(LedStripColors colors);
};

#endif