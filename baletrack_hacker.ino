/* Heres to hoping that this works...
 * 
 * This will hopefully be able to, one day, replace the John Deere BaleTrak Pro
 * with an open source solution.
 * 
 * -William Petefish, 2017
 */

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <william.petefish@gmail.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   -William Petefish
 *
 * Original THE BEER-WARE LICENSE by Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */
 
//initialize sensors
int leftBaleShp = A0;
int rightBaleShp = A1;
int baleDiameterSENS = A2;
int ptoSlip = 17;
//int footSlip = 18;

//initialize the actuators
int twineAct = 13;
int netAct = 12;

//initialize variable core solenoid
int varCore = 11;

//initialize the baler's switches
int oversizeSw = 10;
int rightGateSw = 9;
int leftGateSw = 8;
int netWrapSw = 7;

//initialize the control panel switches
int wrapNow = 6;

//initialize indicators, audible and visual
int oversize = 5;
int ejectNow = 4;
int wrapping = 3;
int slipPto = 2;
//int slipFoot = 14;
int gateClosed = 15;
int buzzer = 16;

//initialize counter for number of bales
int baleCount;

void setup() {
  // setting up pins and connections
pinMode(twineAct, OUTPUT);
pinMode(netAct, OUTPUT);

pinMode(oversizeSw, INPUT);
pinMode(rightGateSw, INPUT);
pinMode(leftGateSw, INPUT);
pinMode(netWrapSw, INPUT);

Serial.begin(9600);

}

void loop() {
  // for now, output the diameter to serial
  int diameter = analogRead(baleDiameterSENS);
  int baleDiameter = map(diameter, 0, 1023, 0, 5.5);
  Serial.println("Diameter=" + baleDiameter);
  
  int shape = analogRead(leftBaleShp-rightBaleShp);
  int baleShp = map(shape, 0, 1023, -6, 6);
  Serial.println("Bale shape is " + baleShp);

//  if (wrapNow == HIGH) {   
//    wrapBale();
//    Serial.println("Wrapping requested");
//  } else if (baleDiameter >= 5.5) {
//    Serial.println("Will start Wrapping shortly... Please Stop.");
//    flashWrapping();
//    wrapBale();
//  } else {
//
//  {
  
}

void wrapBale() { //wrapping for net only at this time
  digitalWrite(netAct, HIGH);
  digitalWrite(wrapping, HIGH);
  delay(5000);
  digitalWrite(netAct, LOW);
  digitalWrite(wrapping, LOW);
  digitalWrite(ejectNow, HIGH);
  digitalWrite(buzzer, HIGH);
  Serial.println("Please Eject the bale now.");
  baleCount++;
  delay(5000);
  digitalWrite(ejectNow, LOW);
  digitalWrite(buzzer, LOW); 
}

void warnUser() { // annoying, but need to get attention
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}

void flashWrapping() { //warning of auto wrap is about to start
  warnUser();
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
  digitalWrite(wrapping, LOW);
  delay(300);
  digitalWrite(wrapping, HIGH);
  delay(300);
}

void oversizeWarn() {
  digitalWrite(oversize, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
  
}

