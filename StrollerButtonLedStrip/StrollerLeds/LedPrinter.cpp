#include "LedPrinter.h"
#include "PololuLedStrip.h"
#include "LedStripColors.h"

PololuLedStrip<12> ledStrip;

void LedPrinter::Print(LedStripColors colors) {
	ledStrip.write(colors.Colors, LED_COUNT);
}