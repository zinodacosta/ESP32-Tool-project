#include "menu.h"
#include "config.h"
#include <Arduino.h>

unsigned long lastDebounceTime_UP = 0;
unsigned long lastDebounceTime_DOWN = 0;
unsigned long lastDebounceTime_LEFT = 0;
unsigned long lastDebounceTime_RIGHT = 0;
unsigned long lastDebounceTime_MIDDLE = 0;

unsigned long debounceDelay = 250;

const char* menuItems[] = {"WIFI", "OPTIONS", "QUIT"};
int totalMenuItems = 3;
int selectedItem = 0;

void setupButtons(){
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_MIDDLE, INPUT_PULLUP);

}

void displayMenu(){
  Serial.println("ESP32 Multi-Tool \n");
  for(int i = 0; i < totalMenuItems; i++){
    if(i == selectedItem){
      Serial.print("> ");
    }else{
    Serial.print(" ");
    }
    Serial.println(menuItems[i]);
  }
  Serial.println();

}


void controlSettings(){

    int upState = digitalRead(BUTTON_UP);
    int downState = digitalRead(BUTTON_DOWN);
    int leftState = digitalRead(BUTTON_LEFT);
    int rightState = digitalRead(BUTTON_RIGHT);
    int middleState = digitalRead(BUTTON_MIDDLE);
  
    if(upState == LOW && (millis() - lastDebounceTime_UP > debounceDelay)){
      lastDebounceTime_UP = millis();
      if(selectedItem > 0){
        selectedItem--;
        displayMenu();
    }
  }
    if(downState == LOW && (millis() - lastDebounceTime_DOWN > debounceDelay)){
      lastDebounceTime_DOWN = millis();
      if(selectedItem < totalMenuItems - 1){
        selectedItem++;
        displayMenu();
    }
    }
    if(middleState == LOW && (millis() - lastDebounceTime_MIDDLE > debounceDelay)){
      lastDebounceTime_MIDDLE = millis();
      switch(selectedItem){
        case 0:
          // WiFi settings
          Serial.println("WiFi Settings");
          break;
        case 1:
          // Options
          Serial.println("Options");
          break;
        case 2:
          // Quit
          Serial.println("Exiting...");
          while(1){} // Loop forever to prevent program from exiting
    }



}

}