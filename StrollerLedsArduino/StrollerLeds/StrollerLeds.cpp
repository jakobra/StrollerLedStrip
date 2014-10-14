#include "StrollerLeds.h"
#include "ButtonInputController.h"
#include "SerialInputController.h"
#include "LedPrinter.h"

ButtonInputController* buttonInputController;
SerialInputController* serialInputController;

void StrollerLeds::Setup() {
	pinMode(BUTTON_PIN, INPUT);
	Serial.begin(9600);
	LedPrinter *ledPrinter = new LedPrinter();
	buttonInputController = new ButtonInputController(*ledPrinter);
	serialInputController = new SerialInputController(*ledPrinter);
}

void StrollerLeds::Execute() {
	buttonInputController->HandleButtonPush();
	serialInputController->HandleSerialInput();
}