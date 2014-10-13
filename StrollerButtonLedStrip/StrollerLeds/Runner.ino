#include "StrollerLeds.h"

StrollerLeds* strollerLeds;

void setup() {
  strollerLeds = new StrollerLeds();
  strollerLeds->Setup();
}

void loop() {
  strollerLeds->Execute();
}