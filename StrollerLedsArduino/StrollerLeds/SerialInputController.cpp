#include "SerialInputController.h"
#include "PololuLedStrip.h"
#include <string>

const int maxLength = 605;
char messageBuffer[maxLength];
int commandPos = 0;

rgb_color params[99];
const int paramLength = 6;
const char endByte = '\r';

SerialInputController::SerialInputController(const LedPrinter &lp) {
	ledPrinter = lp;
}

void SerialInputController::HandleSerialInput() {
	if (ReadSerialInput(Serial.read(), messageBuffer, maxLength) > 0) {
		String message(messageBuffer);
		String command = message.substring(0, 8);
		int paramCount = message.substring(8, 10).toInt();
		ParseParams(paramCount);
		
		if(command == "color000"){
			serialColors.SetColor(params[0]);
		} else {
			Serial.print("Unknown command: ");
			Serial.println(command);
			return;
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

void SerialInputController::ParseParams(int paramCount) {
	if(paramCount < 1) { return; }
	int red = 0;
	int green = 0;
	int blue = 0;
	int paramCharCount = paramCount * paramLength;
	int paramsEndPosition = 9 + paramCharCount;

	for(int i = 10; i <= paramsEndPosition; i++) {
		switch ((i - 10) % paramLength) {
			case 1:
				red = GetIntFromHex(messageBuffer[i-1], messageBuffer[i]);
				break;
			case 3:
				green = GetIntFromHex(messageBuffer[i-1], messageBuffer[i]);
				break;
			case 5:
				blue = GetIntFromHex(messageBuffer[i-1], messageBuffer[i]);
				{
					int paramNumber = (int)((i - 9) / paramLength) - 1;
					params[paramNumber] = (rgb_color){ red, green, blue };
				}
				break;
			default:
				break;
		}
	}
}

int SerialInputController::GetIntFromHex(char first, char second) {
	char value[2] = {first, second};
	return (int) strtol(&value[0], NULL, 16);
}