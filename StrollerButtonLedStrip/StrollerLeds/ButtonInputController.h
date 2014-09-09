#include "PololuLedStrip.h"

#ifndef BUTTON_INPUT_CONTROLLER_H
#define BUTTON_INPUT_CONTROLLER_H

#define LED_COUNT 22

class ButtonInputController {
	private:
		void PlainColor(rgb_color color);
		void Gradient();
	public:
		ButtonInputController() {};
		void HandleButtonPush();
};
 
#endif