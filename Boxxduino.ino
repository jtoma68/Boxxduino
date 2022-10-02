// Boxxduino by Tyler Toma
// Adapted from colpasus's Unosmashbox code: https://github.com/colpasus/UnoSmashbox


/*Version 1.0
Code Changed to Act similar to the Boxx Controller instead of the Smashbox
Added modX and modY to change stick tilt
Disabled L3 and R3
->Replaced digitalRead(pin_LEFT_3) as LOW;
->Replaced digitalRead(pin_RIGHT_3) as LOW;
-> Remapped Y/A to match arduino code.
Removed ZL tilt modifier funtion
Added Right Stick Functionality
Removed Recording Functionality
*/

#include "Smashbox.h"
boolean led = false;
int pinled1 = 13;
int pinled2 = A5;
int pinled3 = A3;
int pinled4 = A4;
int pinb = 12;



int TiltDoubleClick=0;   // If push right and left direction stick at the same time, tilt to the direction of the first pushed (walking, not running).

const int FactorTilt=64;

// -1 LEFT
// 0 NO
// 1 RIGHT

int pin_X=2;
int pin_Y=3;
int pin_A=4;
int pin_B=5;

int pin_dpadUpOn = 6;
int pin_dpadDownOn=7;
int pin_dpadLeftOn=8;
int pin_dpadRightOn=9;

int LeftStick_Top_pin   =  30  ;
int LeftStick_Right_pin =  31  ;
int LeftStick_Down_pin  =  32  ;
int LeftStick_Left_pin  =  33  ;


int RightStick_Top_pin   =  34 ;
int RightStick_Right_pin =  35 ;
int RightStick_Down_pin  =  36 ;
int RightStick_Left_pin  =  37 ;


int pin_SWITCH_L   =  22 ;
int pin_SWITCH_R =    23 ;
int pin_SWITCH_ZL  =  24 ;
int pin_SWITCH_ZR  =  25 ;

//Removed
//int pin_LEFT_3 = 38;
//int pin_RIGHT_3 = 39;




int pin_MinusOn= 26;
int pin_PlusOn=27;
int pin_HomeOn=28;



// Smashbox needs a way to avoid running in some situations.
// tilt inputs will be made using modifier buttons
int pin_modX = 38;
int pin_modY = 39;




void setup(){

  setupPins();
  setupUnoJoy();

 
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinled4, OUTPUT);
  pinMode(pinb, INPUT_PULLUP);
 
}




void loop(){
  if (digitalRead(pinb) == LOW){
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
  }
  else if (digitalRead(pinb) == HIGH){
    if (digitalRead(A1) == LOW){
      led = true;
      }
    else if (digitalRead(A0) == LOW){
      led = true;
      }
    else {
      led = false;
      }
    if (led == true){
      digitalWrite(pinled1, HIGH);
      }
    else {
      digitalWrite(pinled1, LOW);
      }
    if (digitalRead(4) == LOW){
      led = true;
      }
    else if (digitalRead(5) == LOW){
      led = true;
      }
    else {
      led = false;
      }
    if (led == true){
      digitalWrite(pinled2, HIGH);
      }
    else {
      digitalWrite(pinled2, LOW);
      }
    if (digitalRead(3) == LOW){
      led = true;
      }
    else if (digitalRead(2) == LOW){
      led = true;
      }
    else {
      led = false;
      }
    if (led == true){
      digitalWrite(pinled3, HIGH);
      }
    else {
      digitalWrite(pinled3, LOW);
      }
    if (digitalRead(11) == LOW){
      led = true;
      }
    else if (digitalRead(10) == LOW){
      led = true;
      }
    else {
      led = false;
      }
    if (led == true){
      digitalWrite(pinled4, HIGH);
      }
    else {
      digitalWrite(pinled4, LOW);
      }
  }

  
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);


}


void setupPins(void){
  for (int i = 2; i <= 11; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }


//MEGA SET OF BUTTONS

  for (int i = 22; i <= 49; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }

  
  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
}


//Obtain Blank dataForConroller_t structure
dataForController_t getControllerData(void){
  dataForController_t controllerData = getBlankDataForController();



// SET XYAB

  controllerData.triangleOn = !digitalRead(pin_X);
  controllerData.circleOn = !digitalRead(pin_A);    //Changed to match inputs
  controllerData.squareOn = !digitalRead(pin_Y);    //Changed to match inputs
  controllerData.crossOn = !digitalRead(pin_B);


// SET DPAD  
  controllerData.dpadUpOn = !digitalRead(pin_dpadUpOn);
  controllerData.dpadDownOn = !digitalRead(pin_dpadDownOn);
  controllerData.dpadLeftOn = !digitalRead(pin_dpadLeftOn);
  controllerData.dpadRightOn = !digitalRead(pin_dpadRightOn);




// SET LEFT STICK ANALOG VALUE

// LEFT/RIGHT

if (!digitalRead (LeftStick_Right_pin) && !digitalRead (LeftStick_Left_pin)) //if both left and right are pressed
{
  //L-stick is determined to be neutral
  controllerData.leftStickX=   128;
}
else
{
  //When modX is Held,
  if (!digitalRead (pin_modX))
  {
    if (!digitalRead (LeftStick_Right_pin))     controllerData.leftStickX= 128 + FactorTilt;
    if (!digitalRead (LeftStick_Left_pin))     controllerData.leftStickX= 128 - FactorTilt;
  }
  //When modX is Released
  else
  {
    if (!digitalRead (LeftStick_Right_pin))     controllerData.leftStickX= 255;
    if (!digitalRead (LeftStick_Left_pin))     controllerData.leftStickX= 0;
  }
}



// UP/DOWN

if (!digitalRead (LeftStick_Top_pin) && !digitalRead (LeftStick_Down_pin)) //if both up and down are pressed
{
  //L-stick is determined to be neutral
  controllerData.leftStickY=   128;
}
else
{
  //When modY is Held,
  if (!digitalRead (pin_modY))
  {
    if (!digitalRead (LeftStick_Top_pin))     controllerData.leftStickY= 128 - FactorTilt;
    if (!digitalRead (LeftStick_Down_pin))     controllerData.leftStickY= 128 + FactorTilt;
  }
  //When modY is Released
  else
  {
    if (!digitalRead (LeftStick_Top_pin))     controllerData.leftStickY= 0;
    if (!digitalRead (LeftStick_Down_pin))     controllerData.leftStickY= 255;
  }
}


/////////////////////////////////////////////////////////////


// SET RIGHT STICK ANALOG VALUE

// LEFT/RIGHT

if (!digitalRead (RightStick_Right_pin) && !digitalRead (RightStick_Left_pin)) //if both left and right are pressed
{
  //C-stick is determined to be neutral
  controllerData.rightStickX=   128;
}
else
{
    if (!digitalRead (RightStick_Right_pin))     controllerData.rightStickX= 256;
    if (!digitalRead (RightStick_Left_pin))     controllerData.rightStickX= 0;
}


// UP/DOWN

if (!digitalRead (RightStick_Top_pin) && !digitalRead (RightStick_Down_pin)) //if both up and down are pressed
{
  //L-stick is determined to be neutral
  controllerData.rightStickY=   128;
}
else
{
    if (!digitalRead (RightStick_Top_pin))     controllerData.rightStickY= 0;
    if (!digitalRead (RightStick_Down_pin))     controllerData.rightStickY= 255;
}


/////////////////////////////////////////////////////////////


// SET L ZL R ZR

  controllerData.l1On = !digitalRead(pin_SWITCH_L);
  controllerData.l2On = !digitalRead(pin_SWITCH_ZL);
//  controllerData.l3On = !digitalRead(pin_SWITCH_L3);    //removed

  controllerData.r1On = !digitalRead(pin_SWITCH_R);
  controllerData.r2On = !digitalRead(pin_SWITCH_ZR);
//  controllerData.r3On = !digitalRead(pin_SWITCH_R3);    //removed

// HOME SELECT START


  controllerData.MinusOn = !digitalRead(pin_MinusOn);
  controllerData.PlusOn = !digitalRead(pin_PlusOn);
  controllerData.HomeOn = !digitalRead(pin_HomeOn);

 


 
  return controllerData;
}
