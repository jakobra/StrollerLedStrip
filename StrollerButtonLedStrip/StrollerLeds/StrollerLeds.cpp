#include "StrollerLeds.h"
#include "ButtonInputController.h"
#include "Arduino.h"
#include "LedPrinter.h"

ButtonInputController* buttonInputController;

void StrollerLeds::Setup() {
	pinMode(BUTTON_PIN, INPUT);
	LedPrinter *ledPrinter = new LedPrinter();
	buttonInputController = new ButtonInputController(*ledPrinter);
}

void StrollerLeds::Execute() {
	buttonInputController->HandleButtonPush();
	
	delay(10);
}