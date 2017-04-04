 
#define gpsSerial Serial3
#define imuSerial Serial1

#define serialBaud 115200
#define gpsBaud 9600
#define imuBaud 57600

unsigned long StartTime;
void setup()
{
  GPS_setup();
  IMU_setup();
  RF_setup();
  SteeringServo_setup();
  ThrottleServo_setup();
  StartTime = millis();
  
}
 
void loop() {

  writeData ("TIME_MS", String( millis() - StartTime));
  GPS_loop();
  IMU_loop();
  //RF_loop();
  SteeringServo_loop();
  ThrottleServo_loop();
  
  
 /* 
  if(GPS.fix==1) { //Only save data if we have a fix
    mySensorData = SD.open("NMEA.txt", FILE_WRITE); //Open file on SD card for writing
    mySensorData.println(NMEA1); //Write first NMEA to SD card
    mySensorData.println(NMEA2); //Write Second NMEA to SD card
    mySensorData.close();  //Close the file
    mySensorData = SD.open("GPSData.txt", FILE_WRITE);
    mySensorData.print(GPS.latitude,4); //Write measured latitude to file
    mySensorData.print(GPS.lat); //Which hemisphere N or S
    mySensorData.print(",");
    mySensorData.print(GPS.longitude,4); //Write measured longitude to file
    mySensorData.print(GPS.lon); //Which Hemisphere E or W
    mySensorData.print(",");
    mySensorData.println(GPS.altitude);
    mySensorData.close();
  }
  */  
}

