#include "LedPrinter.h"

#ifndef SERIAL_INPUT_CONTROLLER_H
#define SERIAL_INPUT_CONTROLLER_H

class SerialInputController {
	private:
		LedPrinter ledPrinter;
		LedStripColors serialColors;
		int ReadSerialInput(int readch, char *buffer, int len);
		void ParseParams(int paramCount);
		int GetIntFromHex(char first, char second);
	public:
		SerialInputController(const LedPrinter &lp);
		void HandleSerialInput();
};

#endif