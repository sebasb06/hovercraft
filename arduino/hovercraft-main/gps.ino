#include <SoftwareSerial.h>
#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library
 
#include <Adafruit_GPS.h>    //Install the adafruit GPS library
#include <SoftwareSerial.h> //Load the Software Serial library

//SoftwareSerial gpsSerial(8,7); //Initialize the Software Serial port
Adafruit_GPS GPS(&gpsSerial); //Create the GPS Object

//
 
String NMEA1; //Variable for first NMEA sentence
String NMEA2; //Variable for second NMEA sentence
char c; //to read characters coming from the GPS
 
int chipSelect = 53; //chipSelect pin for the SD card Reader
File mySensorData; //Data object you will write your sesnor data to


 void GPSsetup ()
 {
  
  Serial.begin(115200); //Turn on serial monitor
  GPS.begin(9600); //Turn on GPS at 9600 baud
  GPS.sendCommand("$PGCMD,33,0*6D");  //Turn off antenna update nuisance data
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //Request RMC and GGA Sentences only
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); //Set update rate to 1 hz
  delay(1000);
  
  pinMode(10, OUTPUT); //Must declare 10 an output and reserve it to keep SD card happy
  SD.begin(chipSelect); //Initialize the SD card reader
  
  if (SD.exists("NMEA.txt")) { //Delete old data files to start fresh
    SD.remove("NMEA.txt");
  }
  if (SD.exists("GPSData.txt")) { //Delete old data files to start fresh
    SD.remove("GPSData.txt");
  }
 }


void GPSloop()
{
    readGPS();
    String gpsCoords = String(GPS.latitude,4) + GPS.lat + "," + String(GPS.longitude,4) + GPS.lon;
    writeData ("GPS", gpsCoords);

}


void readGPS() {
  
  clearGPS();
  while(!GPS.newNMEAreceived()) { //Loop until you have a good NMEA sentence
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA()); //Parse that last good NMEA sentence
  NMEA1=GPS.lastNMEA();
  
   while(!GPS.newNMEAreceived()) { //Loop until you have a good NMEA sentence
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA()); //Parse that last good NMEA sentence1
  NMEA2=GPS.lastNMEA();

  
/*
    Serial.print(GPS.latitude,4);
    Serial.print(GPS.lat);
    Serial.print(",");
    Serial.print(GPS.longitude,4);
    Serial.println(GPS.lon);
*/

  //Serial.println(NMEA1);
  //Serial.println(NMEA2);
  //Serial.println("");
  
}

 
void clearGPS() {  //Clear old and corrupt data from serial port
  while(!GPS.newNMEAreceived()) { //Loop until you have a good NMEA sentence
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA()); //Parse that last good NMEA sentence
  
  while(!GPS.newNMEAreceived()) { //Loop until you have a good NMEA sentence
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA()); //Parse that last good NMEA sentence
   while(!GPS.newNMEAreceived()) { //Loop until you have a good NMEA sentence
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA()); //Parse that last good NMEA sentence
  
}
