#include "PololuLedStrip.h"

#ifndef LED_STRIP_COLORS_H
#define LED_STRIP_COLORS_H

#define LED_COUNT 22

class LedStripColors {
	public:
		void SetColor(rgb_color color);
		void SetColors(rgb_color colors[]);
		void Gradient();
		rgb_color Colors[LED_COUNT];
};

#endif