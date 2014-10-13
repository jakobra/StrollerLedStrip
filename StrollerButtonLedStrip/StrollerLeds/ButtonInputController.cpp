#include "ButtonInputController.h"
#include "Arduino.h"
#include "PololuLedStrip.h"
#include "StrollerLeds.h"
#include "LedPrinter.h"
#include "LedStripColors.h"

int buttonState = 0;
int buttonLoop = 0;

const rgb_color green = (rgb_color){ 0, 255, 0 };
const rgb_color blue = (rgb_color){ 0, 0, 255 };
const rgb_color pink = (rgb_color){ 255, 0, 255 };
const rgb_color white = (rgb_color){ 255, 255, 255 };
const rgb_color black = (rgb_color){ 0, 0, 0 };

ButtonInputController::ButtonInputController(const LedPrinter &lp) {
	ledPrinter = lp;
}

void ButtonInputController::HandleButtonPush() {
	int newButtonState = digitalRead(BUTTON_PIN);

	if (buttonState == LOW && newButtonState == HIGH) {
		buttonState = newButtonState;
		buttonLoop++;
	} else if (newButtonState == LOW && buttonState == HIGH) {
		buttonState = newButtonState;
		return;
	} else {
		return;
	}

	switch (buttonLoop % 6) {
		case 0:
			buttonColors.SetColor(blue);
			break;
		case 1:
			buttonColors.SetColor(green);
			break;
		case 2:
			buttonColors.SetColor(pink);
			break;
		case 3:
			buttonColors.SetColor(white);
			break;
		case 4:
			buttonColors.Gradient();
			break;
		case 5:
			buttonColors.SetColor(black);
			break;
	}

	ledPrinter.Print(buttonColors);
}
