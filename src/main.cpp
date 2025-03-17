#include <Arduino.h>
#include "config.h"
#include "menu.h"





void setup() {
  Serial.begin(115200);
  
  setupButtons();

  Serial.println("ESP32 Multi-Tool");
}

void loop() {

  displayMenu();

}