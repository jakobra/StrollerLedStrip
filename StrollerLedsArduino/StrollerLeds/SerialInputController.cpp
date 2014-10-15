#include "SerialInputController.h"
#include "PololuLedStrip.h"
#include <string>

const rgb_color green = (rgb_color){ 0, 255, 0 };
const rgb_color blue = (rgb_color){ 0, 0, 255 };
const rgb_color pink = (rgb_color){ 255, 0, 255 };
const rgb_color white = (rgb_color){ 255, 255, 255 };
const rgb_color black = (rgb_color){ 0, 0, 0 };

const int maxLength = 1010;
char messageBuffer[maxLength];
int commandPos = 0;

int paramPos = 0;
const char endByte = '\r';

SerialInputController::SerialInputController(const LedPrinter &lp) {
	ledPrinter = lp;
}

void SerialInputController::HandleSerialInput() {
 	if (ReadSerialInput(Serial.read(), messageBuffer, maxLength) > 0) {
 		String message(messageBuffer);
 		String command = message.substring(0, 7);
 		int paramCount = message.substring(7, 10).toInt();
		Serial.print("I received: ");
		Serial.println(command);
		Serial.println(paramCount);
		
		if(command == "blue000")
			serialColors.SetColor(blue);
		else if(command == "green00")
			serialColors.SetColor(green);
		else if(command == "pink000")
			serialColors.SetColor(pink);
		else
			serialColors.SetColor(pink);

		for(int i = 10; i < paramCount + 10; i++) {
			Serial.println(messageBuffer[i]);
		}

		ledPrinter.Print(serialColors);
		Serial.println("ack");
	}
}


int SerialInputController::ReadSerialInput(int readch, char *buffer, int len) {
	int rpos;

	if (readch > 0) {
		switch (readch) {
			case '\n':
				break;
			case endByte:
				rpos = commandPos;
				commandPos = 0;
				return rpos;
			default:
				if (commandPos < len-1) {
					buffer[commandPos++] = readch;
					buffer[commandPos] = 0;
				}
		}
	}

	return -1;
}