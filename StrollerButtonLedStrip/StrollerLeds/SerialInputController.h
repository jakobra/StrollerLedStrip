#include "LedPrinter.h"

#ifndef SERIAL_INPUT_CONTROLLER_H
#define SERIAL_INPUT_CONTROLLER_H

class SerialInputController {
	private:
		LedPrinter ledPrinter;
		LedStripColors serialColors;
	public:
		SerialInputController(const LedPrinter &lp);
		void HandleSerialInput();
};

#endif