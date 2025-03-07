/* 
 * Project myProject
 * Author: Sofia Cortes
 * Date: 06-March-2025
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "hue.h"
#include "button.h"
#include <Encoder.h>
#include "wemo.h"

SYSTEM_MODE(MANUAL);

const int BULB1=1; 
const int BULB2=2; 
const int BULB3=3; 
const int BULB4=4; 
const int BULB5=5;
const int BULB6=6;  
int BULBS[] {BULB1,BULB2,BULB3,BULB4,BULB5,BULB6};
const int MYWEMO0=0;
const int MYWEMO1=0;
const int MYWEMO2=2;
const int MYWEMO3=3;
const int MYWEMO4=4;
const int MYWEMO5=5;
int MYWEMOS[] {MYWEMO0,MYWEMO1,MYWEMO2,MYWEMO3,MYWEMO4,MYWEMO5};
int color;
int value;

const int PHOTODIODE1 = D11;
const int PHOTODIODE2 = D12;
const int PHOTODIODE3 = D13;
const int PHOTODIODE4 = D14;
const int PHOTODIODE5 = D19;
const int PHOTODIODE6 = D18;
const int PHOTODIODEHOLE = D17;
int value1;
int value2;
int value3;
int value4;
int value5;
int value6;
int valueHole;
int brightness;
String Brightness, Value;
bool prevValue1=0;

bool prevPosition=0;
int position; 
bool buttonState;
bool switchState;
bool prevSwitchState;
bool isclicked;
const int SWITCHPIN= D6;
int inputValue;
Button BUTTON(D13);
Button SWITCH(SWITCHPIN);
const int PINA = D10;
const int PINB = D7;
Encoder myEnc (PINA,PINB);

Button BUTTONSERVO(D5);
bool buttonServoState;
bool prevButtonServoState;
bool onOrOff;
float frequency; 
int positionButton;
float t;

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,15000);

  pinMode (PHOTODIODE1,INPUT);
  pinMode (PHOTODIODE2,INPUT);
  pinMode (PHOTODIODE3,INPUT);
  pinMode (PHOTODIODE4,INPUT);
  pinMode (PHOTODIODE5,INPUT);
  pinMode (PHOTODIODE6,INPUT);

  WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  }
  Serial.printf("\n\n"); 
  


//pinMode(BUTTONSERVO);
  //myServo.attach(D4);
}

void loop() {

  value1 = analogRead(PHOTODIODE1);
  Serial.printf("AnalogRead value = %i\n",value1);
  position = myEnc.read();

  if (value1<15){
    Serial.printf("%i \n",value1);
    Serial.printf("Setting bulb %i to brightness %06i\n",BULB1,HueRainbow[color%7]);
    setHue(BULB1,TRUE,HueRainbow[color%7],position,255);

    }
    else{
    setHue(BULB1,FALSE,HueRainbow[color%7],position,255);
    }


  if (position>255){
     position=255;
     myEnc.write (255);
  }
  if(position<0){
      position=0;
      myEnc.write(0);
  }
  if(position != prevPosition){
    Serial.printf("%i \n",position);
    Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
    setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
    }
  if (SWITCH.isClicked()){
    switchState = !prevSwitchState;
   if (switchState == TRUE ){
   Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
    setHue(BULBS[5],true,HueRainbow[color%7],position,255);
     color++;
   }
  }
  //BULB2 

  value2 = analogRead(PHOTODIODE2);
  Serial.printf("AnalogRead value = %i\n",value2);
  position = myEnc.read();

  if (value2<15){
    Serial.printf("%i \n",value2);
    Serial.printf("Setting bulb %i to brightness %06i\n",BULB2,HueRainbow[color%7]);
    setHue(BULB2,TRUE,HueRainbow[color%7],position,255);

    }
    else{
    setHue(BULB2,FALSE,HueRainbow[color%7],position,255);
    }


  if (position>255){
     position=255;
     myEnc.write (255);
  }
  if(position<0){
      position=0;
      myEnc.write(0);
  }
  if(position != prevPosition){
    Serial.printf("%i \n",position);
    Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
    setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
    }
  if (SWITCH.isClicked()){
    switchState = !prevSwitchState;
   if (switchState == TRUE ){
   Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
    setHue(BULBS[5],true,HueRainbow[color%7],position,255);
     color++;
   }
  }
//BULB3 

value3 = analogRead(PHOTODIODE3);
Serial.printf("AnalogRead value = %i\n",value3);
position = myEnc.read();

if (value3<15){
  Serial.printf("%i \n",value3);
  Serial.printf("Setting bulb %i to brightness %06i\n",BULB3,HueRainbow[color%7]);
  setHue(BULB3,TRUE,HueRainbow[color%7],position,255);

  }
  else{
  setHue(BULB3,FALSE,HueRainbow[color%7],position,255);
  }


if (position>255){
   position=255;
   myEnc.write (255);
}
if(position<0){
    position=0;
    myEnc.write(0);
}
if(position != prevPosition){
  Serial.printf("%i \n",position);
  Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
  setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
  }
if (SWITCH.isClicked()){
  switchState = !prevSwitchState;
 if (switchState == TRUE ){
 Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
  setHue(BULBS[5],true,HueRainbow[color%7],position,255);
   color++;
 }
}
//BULB4 

value4 = analogRead(PHOTODIODE4);
Serial.printf("AnalogRead value = %i\n",value4);
position = myEnc.read();

if (value4<15){
  Serial.printf("%i \n",value4);
  Serial.printf("Setting bulb %i to brightness %06i\n",BULB4,HueRainbow[color%7]);
  setHue(BULB4,TRUE,HueRainbow[color%7],position,255);

  }
  else{
  setHue(BULB4,FALSE,HueRainbow[color%7],position,255);
  }


if (position>255){
   position=255;
   myEnc.write (255);
}
if(position<0){
    position=0;
    myEnc.write(0);
}
if(position != prevPosition){
  Serial.printf("%i \n",position);
  Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
  setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
  }
if (SWITCH.isClicked()){
  switchState = !prevSwitchState;
 if (switchState == TRUE ){
 Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
  setHue(BULBS[5],true,HueRainbow[color%7],position,255);
   color++;
 }
}

//BULB 5 

value5 = analogRead(PHOTODIODE5);
Serial.printf("AnalogRead value = %i\n",value5);
position = myEnc.read();

if (value5<15){
  Serial.printf("%i \n",value5);
  //Serial.printf(" bulb 5 %i to brightness %06i\n",BULB5,HueRainbow[color%7]);
  Serial.printf(" bulb 5 ON\n");
  setHue(BULB5,TRUE,HueRainbow[color%7],position,255);

  }
  else{
  setHue(BULB5,FALSE,HueRainbow[color%7],position,255);
  Serial.printf(" bulb 5 OFF\n");
  }

if (position>255){
   position=255;
   myEnc.write (255);
}
if(position<0){
    position=0;
    myEnc.write(0);
}
if(position != prevPosition){
  Serial.printf("%i \n",position);
  Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
  setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
  }
if (SWITCH.isClicked()){
  switchState = !prevSwitchState;
 if (switchState == TRUE ){
 Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
  setHue(BULBS[5],true,HueRainbow[color%7],position,255);
   color++;
 }
}

//BULB6 

value6 = analogRead(PHOTODIODE6);
Serial.printf("AnalogRead value = %i\n",value6);
position = myEnc.read();

if (value6<15){
  Serial.printf("%i \n",value6);
  Serial.printf("Setting bulb %i to brightness %06i\n",BULB6,HueRainbow[color%7]);
  setHue(BULB6,TRUE,HueRainbow[color%7],position,255);

  }
  else{
  setHue(BULB6,FALSE,HueRainbow[color%7],position,255);
  }


if (position>255){
   position=255;
   myEnc.write (255);
}
if(position<0){
    position=0;
    myEnc.write(0);
}
if(position != prevPosition){
  Serial.printf("%i \n",position);
  Serial.printf("Setting brightness of bulb %i to brightness %06i\n",BULBS[5],position);
  setHue(BULBS[5],buttonState,HueRainbow[color%7],position,255);
  }
if (SWITCH.isClicked()){
  switchState = !prevSwitchState;
 if (switchState == TRUE ){
 Serial.printf("Setting color of bulb %i to color %06i\n",BULBS[5],HueRainbow[color%7]);
  setHue(BULBS[5],true,HueRainbow[color%7],position,255);
   color++;
 }
}
//Wemos
valueHole = analogRead(PHOTODIODEHOLE);
if (valueHole<15){
  Serial.printf("Turning on Wemo# %i\n",MYWEMO0);
  wemoWrite(MYWEMO0,HIGH);
}
  else{
    Serial.printf("Turning off Wemo# %i\n",MYWEMO0);
    wemoWrite(MYWEMO0,LOW);

}
// Servo

// if(BUTTONSERVO.isClicked()){  
//   onOrOff=!onOrOff;
// }
// if (onOrOff){
//   t =millis()/1000.0;
//   frequency = 90*sin(2*M_PI*0.2*t)+90;
//   myServo.write(frequency);
// }
// else{
//   myServo.write(0);

// }
}