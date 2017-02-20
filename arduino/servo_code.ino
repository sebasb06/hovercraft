#include <Servo.h>
int pos = 0;    // variable to store the servo position
int servoPin= 9;
int servoDelay=60;
Servo myPointer;
 
void setup()
{
  Serial.begin(9600);

  myPointer.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}
void loop() {
  
  for (pos=60; pos<=61; pos=pos+1) {

  myPointer.write(pos);
 delay(30000);

}
 
for (pos=61; pos<=170; pos=pos+1) {

  myPointer.write(pos);
  delay(servoDelay);
 
}

delay(30000);

for (pos=170; pos>=61; pos=pos-1) {

  myPointer.write(pos);
  delay(servoDelay);
 
}
delay(30000);
for (pos=61; pos>=10; pos=pos-1) {

  myPointer.write(pos);
  delay(servoDelay);
  
}
 delay(30000);
for (pos=10; pos<=61; pos=pos+1) {

  myPointer.write(pos);
delay(servoDelay);

}

}

