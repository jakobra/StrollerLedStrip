#pragma once

#include <PololuLedStrip.h>

namespace StrollerLed {
	#define BUTTON_PIN 11
	#define LED_COUNT 22

	rgb_color colors[LED_COUNT];
}

using namespace StrollerLed;