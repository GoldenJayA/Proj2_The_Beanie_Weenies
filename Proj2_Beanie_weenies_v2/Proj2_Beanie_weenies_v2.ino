/* 
AET Jackie & the Beans Project
Group Name: The Beanie Weenies
Members: Belice Rivarola, Jaime Bunker, Angel Jaimes
Description: button and servo program
Fable: Jack & The Giant Beanstalk
*/

// servo code library 
#include<Servo.h>

//VARIABLES
Servo myServo;
const int buttonPin = 7;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); //using .attach to initialize servo to pin 9
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  
}

void loop() {
 
  // put your main code here, to run repeatedly:
  //if button is pressed, swivel servo 180 degrees

  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState){
     if (digitalRead(buttonPin) == HIGH){
    myServo.write(180);
    } else {
      myServo.write(0);
    }    
  }
//Down here is to reset the button state so that you can perform the action again if you place the switch on back again
  lastButtonState = buttonState;
  //maybe add a counter to make it only do it once and not again, think about it.

  //Checkout the StateChangeDetection by going to File>Examples>Digital>StateChangeDetection

//This is to check our switch in the serial monitor to see if its recieving any power (0 = no power, 1 = yes power)
Serial.println(digitalRead(buttonPin));

}
