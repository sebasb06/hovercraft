#include <Servo.h>
//int pos = 0;    // variable to store the servo position
int servoPin= 9;
//int servoDelay=20;
//Servo myPointer;
 
void ThrottleServo_setup()
{
  Serial.begin(9600);

  myPointer.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void ThrottleServo_TurnOn()
{
  for (pos=30; pos<=67; pos=pos+1) 
  { // zero point 
    myPointer.write(pos);
    delay(20);
  }
}

void ThrottleServo_TurnOff()
{
  for (pos=67; pos>=30; pos=pos-1) 
  {// turn left 
    myPointer.write(pos);
    delay(servoDelay);
  }  
}

void ThrottleServo_loop() 
{
  


}

