
#include <Servo.h>
#include "FastLED.h"
#define GREEN 3
#define TILT_START 38
#define TILT_END 54

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif
#define DATA_PIN
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 40
CRGB led_slots[NUM_LEDS];
#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120



Servo myservo;
int servo_pos;
int closed = 170;
int vend = 90;

void setup() {
  Serial.begin(115200);
  //Neopixels
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(led_slots, NUM_LEDS).setCorrection(TypicalLEDStrip);  
  FastLED.setBrightness(BRIGHTNESS);
  //led outs
  pinMode( 3, OUTPUT);
  pinMode( 5, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode (11,INPUT_PULLUP);
  pinMode (12,INPUT_PULLUP);
  myservo.attach(10);
  myservo.write(closed);

  //Tilt switch init
  for (int i = TILT_START; i <TILT_END; i++){
    pinMode( i , INPUT_PULLUP);
  }

  
}

void loop() {

//basic vend logic
  if (digitalRead(11) == 0){
    
    while ( digitalRead(12) == 1) {
      myservo.write(vend);
      analogWrite(GREEN,250);
      analogWrite(5,0);
      analogWrite(6,0);}
      
    myservo.write(closed);
    analogWrite(GREEN,0);
    analogWrite(5,255);
    analogWrite(6,255);
  }
}

void check_slots(){
  for (int i = 38; i <54; i++){
    if (digitalRead(i) == 0){
      Serial.print("Pin"); 
      Serial.println(i);
    }
  }
}

