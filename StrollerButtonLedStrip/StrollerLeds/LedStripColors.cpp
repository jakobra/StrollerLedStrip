#include "LedStripColors.h"
#include "PololuLedStrip.h"

void LedStripColors::SetColor(rgb_color color) {
	for(uint16_t i = 0; i < LED_COUNT; i++) {
		Colors[i] = color;
	}
}

void LedStripColors::SetColors(rgb_color colors[]) {
	for(uint16_t i = 0; i < LED_COUNT; i++) {
		Colors[i] = colors[i];
	}
}

void LedStripColors::Gradient() {
	byte time = millis() >> 2;
	for(uint16_t i = 0; i < LED_COUNT; i++) {
		byte x = time - 8 * i;
		Colors[i] = (rgb_color){ x, 255 - x, x };
	}
}