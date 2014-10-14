#include "SerialInputController.h"
#include "PololuLedStrip.h"
#include <string>

const rgb_color green = (rgb_color){ 0, 255, 0 };
const rgb_color blue = (rgb_color){ 0, 0, 255 };
const rgb_color pink = (rgb_color){ 255, 0, 255 };
const rgb_color white = (rgb_color){ 255, 255, 255 };
const rgb_color black = (rgb_color){ 0, 0, 0 };

SerialInputController::SerialInputController(const LedPrinter &lp) {
	ledPrinter = lp;
}

void SerialInputController::HandleSerialInput() {
	static char buffer[80];
 	if (readline(Serial.read(), buffer, 80) > 0) {
		Serial.print("You entered: >");
		Serial.print(buffer);
		Serial.println("<");
	}
	char messageType[10];
	char incomingByte;
	if (Serial.available() > 10) {
		String command = Serial.readStringUntil('$');
		//for(uint16_t i = 0; i < 10; i++) {
			//incomingByte = Serial.read();
			//messageType[i] = incomingByte;
			//Serial.println(incomingByte);
		//}
			Serial.print("I received: ");
			Serial.println(command);
		
			if(command == "000000blue")
				serialColors.SetColor(blue);
			else if(command == "00000green")
				serialColors.SetColor(green);
			else if(command == "000000pink")
				serialColors.SetColor(pink);
			else
				serialColors.SetColor(pink);

			ledPrinter.Print(serialColors);
	}
}


bool SerialInputController::ReadSerialInput(int readch, char *buffer, int len) {
	static int pos = 0;
	int rpos;

	if (readch > 0) {
		switch (readch) {
		case '\n': // Ignore new-lines
			break;
		case '\r': // Return on CR
			rpos = pos;
			pos = 0;  // Reset position index ready for next time
			return rpos;
		default:
			if (pos < len-1) {
				buffer[pos++] = readch;
				buffer[pos] = 0;
			}
		}
	}
	// No end of line has been found, so return -1.
	return -1;
}