#include <Arduino.h>

#define LED_PIN 2 


#define BUTTON_UP 27
#define BUTTON_DOWN 26
#define BUTTON_LEFT 25
#define BUTTON_RIGHT 33
#define BUTTON_MIDDLE 32

#define BUTTON_SET 35
#define BUTTON_RESET 34



unsigned long lastDebounceTime_UP = 0;
unsigned long lastDebounceTime_DOWN = 0;
unsigned long lastDebounceTime_LEFT = 0;
unsigned long lastDebounceTime_RIGHT = 0;
unsigned long lastDebounceTime_MIDDLE = 0;



unsigned long debounceDelay = 250;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_MIDDLE, INPUT_PULLUP);


   
  Serial.println("ESP32 Multi-Tool");
}

void loop() {
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
