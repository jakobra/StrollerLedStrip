#include <PololuLedStrip.h>

#define BUTTON_PIN 11
#define LED_COUNT 22

PololuLedStrip<12> ledStrip;

rgb_color colors[LED_COUNT];

rgb_color new_color;

void setup() {
  pinMode(BUTTON_PIN, INPUT);   
}

void loop() {
  
  handle_button_push();
  ledStrip.write(colors, LED_COUNT);
  
  delay(10);
}

int buttonState = 0;
int buttonLoop = 0;

const rgb_color green = (rgb_color){ 0, 255, 0 };
const rgb_color blue = (rgb_color){ 0, 0, 255 };
const rgb_color pink = (rgb_color){ 255, 0, 255 };
const rgb_color white = (rgb_color){ 255, 255, 255 };
const rgb_color black = (rgb_color){ 0, 0, 0 };

void handle_button_push() {
  int newButtonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW && newButtonState == HIGH) {
    buttonState = newButtonState;
    buttonLoop++;
  } else if (newButtonState == LOW && buttonState == HIGH) {
    buttonState = newButtonState;
  }
  
  switch (buttonLoop % 6) {
    case 0:
      plain_color(blue);
      break;
    case 1:
      plain_color(green);
      break;
    case 2:
      plain_color(pink);
      break;
    case 3:
      plain_color(white);
      break;
    case 4:
      gradient();
      break;
    case 5:
      plain_color(black);
      break;
  }
}

void plain_color(rgb_color color) {
  for(uint16_t i = 0; i < LED_COUNT; i++) {
    colors[i] = color;
  }
}

void gradient() {
  byte time = millis() >> 2;
  for(uint16_t i = 0; i < LED_COUNT; i++) {
    byte x = time - 8 * i;
    colors[i] = (rgb_color){ x, 255 - x, x };
  }
}