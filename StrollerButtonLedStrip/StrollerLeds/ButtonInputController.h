#include "LedPrinter.h"

#ifndef BUTTON_INPUT_CONTROLLER_H
#define BUTTON_INPUT_CONTROLLER_H

class ButtonInputController {
	private:
		LedPrinter ledPrinter;
		LedStripColors buttonColors;
	public:
		ButtonInputController(const LedPrinter &lp);
		void HandleButtonPush();
};

#endif