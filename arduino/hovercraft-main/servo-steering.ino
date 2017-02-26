#include <Servo.h>
int pos = 0;    // variable to store the servo position
int steeringServoPin= 10; // was servoPin
int servoDelay=120;
Servo myPointer; // was myPointer
 
void SteeringServo_setup()
{
  Serial.begin(9600);

  myPointer.attach(steeringServoPin);  // attaches the servo on pin 9 to the servo object
}

void SteeringServo_loop() 
{
  
  for (pos=86; pos<=87; pos=pos+1) 
  { // zero point 
    myPointer.write(pos);
    delay(10000);
  }
  
  for (pos=87; pos<=120; pos=pos+1) 
  { // turn right
    myPointer.write(pos);
   delay(servoDelay);
  }
  
  delay(10000);

  for (pos=120; pos>=87; pos=pos-1) {// back to zero point 

  myPointer.write(pos);
  delay(servoDelay);
 
}
delay(10000);
for (pos=87; pos>=30; pos=pos-1) {// turn left 

  myPointer.write(pos);
  delay(servoDelay);
  
}
 delay(10000);
for (pos=30; pos<=87; pos=pos+1) {// back to zero point

  myPointer.write(pos);
delay(servoDelay);

}

}

