#include "ButtonInputController.h"
#include "Arduino.h"
#include "PololuLedStrip.h"
#include "StrollerLeds.h"

PololuLedStrip<12> ledStrip;

rgb_color colors[LED_COUNT];

int buttonState = 0;
int buttonLoop = 0;

const rgb_color green = (rgb_color){ 0, 255, 0 };
const rgb_color blue = (rgb_color){ 0, 0, 255 };
const rgb_color pink = (rgb_color){ 255, 0, 255 };
const rgb_color white = (rgb_color){ 255, 255, 255 };
const rgb_color black = (rgb_color){ 0, 0, 0 };

void ButtonInputController::HandleButtonPush() {
	int newButtonState = digitalRead(BUTTON_PIN);

	if (buttonState == LOW && newButtonState == HIGH) {
		buttonState = newButtonState;
		buttonLoop++;
	} else if (newButtonState == LOW && buttonState == HIGH) {
		buttonState = newButtonState;
		return;
	}

	switch (buttonLoop % 6) {
		case 0:
			PlainColor(blue);
			break;
		case 1:
			PlainColor(green);
			break;
		case 2:
			PlainColor(pink);
			break;
		case 3:
			PlainColor(white);
			break;
		case 4:
			Gradient();
			break;
		case 5:
			PlainColor(black);
			break;
	}

	ledStrip.write(colors, LED_COUNT);
}

void ButtonInputController::PlainColor(rgb_color color) {
	for(uint16_t i = 0; i < LED_COUNT; i++) {
		colors[i] = color;
	}
}

void ButtonInputController::Gradient() {
	byte time = millis() >> 2;
	for(uint16_t i = 0; i < LED_COUNT; i++) {
		byte x = time - 8 * i;
		colors[i] = (rgb_color){ x, 255 - x, x };
	}
}