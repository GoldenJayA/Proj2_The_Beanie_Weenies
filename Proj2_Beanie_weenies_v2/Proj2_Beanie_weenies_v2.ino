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
int buttonStateBean = 0;
int buttonStateSpeech = 0;
int lastButtonStateBean = 0;
int lastButtonStateSpeech = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  beanStalk.attach(12); //using .attach to initialize servo to pin 9
  pinMode(beanStalkPin, INPUT);
  speechBubble.attach(9);
  pinMode(speechBubPin, INPUT);
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
    } else {
      beanStalk.write(0);
    }    
  }
 Serial.println(counter);
  lastButtonStateBean = buttonStateBean;


/* For the speech bubble */
  buttonStateSpeech = digitalRead(speechBubPin);
  if (buttonStateSpeech != lastButtonStateSpeech){
    speechBubble.write(0);
     if (digitalRead(speechBubPin) == HIGH){
    speechBubble.write(180);
    } else {
      speechBubble.write(0);
    }    
  }
  lastButtonStateSpeech = buttonStateSpeech;


//Down here is to reset the button state so that you can perform the action again if you place the switch on back again
  //maybe add a counter to make it only do it once and not again, think about it.
  //Checkout the StateChangeDetection by going to File>Examples>Digital>StateChangeDetection

//This is to check our switch in the serial monitor to see if its recieving any power (0 = no power, 1 = yes power)
//Serial.println(digitalRead(beanStalkPin));

}
