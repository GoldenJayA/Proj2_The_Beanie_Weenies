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
Servo beanStalk;
const int beanStalkPin = 13;
Servo speechBubble;
const int speechBubPin = 10;
Servo wServo;

//LED lights
const int ledPin =  2;      //green
const int ledPin2 = 3;      //yellow
const int ledPin3 = 4;      //red
int blinks = 200;

const int wSWITCH=1;
int wSwitchVal;
int buttonStateBean = 0;
int buttonStateSpeech = 0;
int lastButtonStateBean = 0;
int lastButtonStateSpeech = 0;
int counter = 0;

void setup() {
  beanStalk.attach(12);
  pinMode(beanStalkPin, INPUT);
  speechBubble.attach(9);
  pinMode(speechBubPin, INPUT);
  wServo.attach(7);
  wServo.write(0);
  pinMode(wSWITCH,INPUT);
  digitalWrite(wSWITCH,LOW);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);

  
}

void loop() {
  
  buttonStateBean = digitalRead(beanStalkPin);

/* code for the beanstalk servo */
if (counter == 0) {
  beanStalk.write(0);
  counter ++;
  } else {
    }
  if (buttonStateBean != lastButtonStateBean){
    beanStalk.write(0);
     if (digitalRead(beanStalkPin) == HIGH){
    beanStalk.write(120);
    digitalWrite(ledPin, HIGH);
    delay(blinks);
    digitalWrite(ledPin, LOW);
    delay(blinks);
    digitalWrite(ledPin2, HIGH);
    delay(blinks);
    digitalWrite(ledPin2, LOW);
    delay(blinks);
    digitalWrite(ledPin3, HIGH);
    delay(blinks);
    digitalWrite(ledPin3, LOW);
    delay(blinks);
    } else {
      beanStalk.write(0);
    }    
  }
 Serial.println(counter);
  lastButtonStateBean = buttonStateBean;


/* For the speech bubble */
  buttonStateSpeech = digitalRead(speechBubPin);
  if (buttonStateSpeech != lastButtonStateSpeech){
    speechBubble.write(180);
     if (digitalRead(speechBubPin) == HIGH){
    speechBubble.write(0);
    } else {
      speechBubble.write(180);
    }    
  }
  lastButtonStateSpeech = buttonStateSpeech;
    wSwitchVal= digitalRead(wSWITCH);
  //Serial.println(wSwitchVal);
  if(wSwitchVal==HIGH){
    wServo.write(180);}
    else{
      wServo.write(0);}


//Down here is to reset the button state so that you can perform the action again if you place the switch on back again
  //maybe add a counter to make it only do it once and not again, think about it.
  //Checkout the StateChangeDetection by going to File>Examples>Digital>StateChangeDetection

//This is to check our switch in the serial monitor to see if its recieving any power (0 = no power, 1 = yes power)
Serial.println(digitalRead(beanStalkPin));

}
