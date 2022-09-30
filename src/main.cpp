// I, Martin De Jesus Gonzalez Santos, 000790179 certify that this is my original work.

// Mohawk College - COMP-10184
//
// Pulse Width Modulation - Test Program
//
#include <Arduino.h>

int button = D5;
int LED = D4;
int resistor = A0;

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);

  // configure pin D5 as digital input - this is the pushbutton
  pinMode(button, INPUT_PULLUP);

  // configure pin D4 as a digital output - this is the LED
  pinMode(LED, OUTPUT);

  // set default PWM range
  analogWriteRange(1023);

}

void loop()
{
  int buttonValue = digitalRead(button);  
  if (buttonValue == 1)
  {
    Serial.println("LED is off ");
    digitalWrite(LED, buttonValue);
  }
  else
  {
    Serial.println("LED is on ");
    analogWrite(LED, analogRead(resistor));    
  }
  delay(1);
}