#include "PololuLedStrip.h"
#include "LedPrinter.h"

#ifndef BUTTON_INPUT_CONTROLLER_H
#define BUTTON_INPUT_CONTROLLER_H

class ButtonInputController {
	private:
		void PlainColor(rgb_color color);
		void Gradient();
		LedPrinter ledPrinter;
	public:
		ButtonInputController(const LedPrinter &lp);
		void HandleButtonPush();
};

#endif