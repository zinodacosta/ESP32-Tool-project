#include <Arduino.h>
#include "config.h"
#include "menu.h"





void setup() {
  Serial.begin(115200);
  
  setupButtons();
  displayMenu();

}

void loop() {
  controlSettings();

}