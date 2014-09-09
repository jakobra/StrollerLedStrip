#include "LedPrinter.h"
#include "PololuLedStrip.h"

PololuLedStrip<12> ledStrip;

void LedPrinter::Print() {
	ledStrip.write(Colors, LED_COUNT);
}