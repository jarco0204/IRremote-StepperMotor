#include <IRremote.h>
#include "Stepper.h"

//Variables
#define STEPS 32 //Number of steps per revolution of internal shaft
int Steps2Take; // 2048=1 Revolution
int receiver = 6;
IRrecv irrecv(receiver);
decode_results results;

//DECLare objects
Stepper small_stepper(STEPS,8,10,9,11);


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600); To initialize the console to print
  irrecv.enableIRIn(); // start the receiver

}
// + FFA857
// - FFE01F
void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) //Is there an IR signal?
  {
    switch(results.value)
    {
      case 0xFFA857: //Plus button
      {
        small_stepper.setSpeed(700);
        Steps2Take =2048;
        small_stepper.step(Steps2Take);
        delay(2000);
        break;
        }
        case 0xFFE01F:
        {
          small_stepper.setSpeed(500);
          Steps2Take=-2048;
          small_stepper.step(Steps2Take);
          delay(2000);
          break;
          }
      }
      irrecv.resume();// receive the next value
   }
   delay(100);

}
