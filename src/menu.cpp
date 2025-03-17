#include "menu.h"
#include "config.h"
#include <Arduino.h>



unsigned long lastDebounceTime_UP = 0;
unsigned long lastDebounceTime_DOWN = 0;
unsigned long lastDebounceTime_LEFT = 0;
unsigned long lastDebounceTime_RIGHT = 0;
unsigned long lastDebounceTime_MIDDLE = 0;



unsigned long debounceDelay = 250;


void setupButtons(){
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_MIDDLE, INPUT_PULLUP);


}


void displayMenu(){
    int upState = digitalRead(BUTTON_UP);
    int downState = digitalRead(BUTTON_DOWN);
    int leftState = digitalRead(BUTTON_LEFT);
    int rightState = digitalRead(BUTTON_RIGHT);
    int middleState = digitalRead(BUTTON_MIDDLE);
  
    if(upState == LOW && (millis() - lastDebounceTime_UP > debounceDelay)){
      lastDebounceTime_UP = millis();
      Serial.println("UP");
    }
    if(downState == LOW && (millis() - lastDebounceTime_DOWN > debounceDelay)){
      lastDebounceTime_DOWN = millis();
      Serial.println("DOWN");
    }
    if(leftState == LOW && (millis() - lastDebounceTime_LEFT > debounceDelay)){
      lastDebounceTime_LEFT = millis();
      Serial.println("LEFT");
    }
    if(rightState == LOW && (millis() - lastDebounceTime_RIGHT > debounceDelay)){
      lastDebounceTime_RIGHT = millis();
      Serial.println("RIGHT");
    }
    if(middleState == LOW && (millis() - lastDebounceTime_MIDDLE > debounceDelay)){
      lastDebounceTime_MIDDLE = millis();
      Serial.println("MIDDLE");
    }
  

}