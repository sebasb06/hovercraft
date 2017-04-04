
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <math.h>
#include <Servo.h>
/*
      4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx)
*/
static const int RXPin = 0, TXPin = 1; //kompass connections 

static const uint32_t GPSBaud = 4800;
double compass_headingDegrees;

//servos control

Servo Throttle;
Servo Steer;


// The TinyGPS++ object from the library
TinyGPSPlus gps;
// the HMC5883L object
HMC5883L compass;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);

  Serial.println(F("FullExample.ino"));
  Serial.println(F("An extensive example of many interesting TinyGPS++ features"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
  Serial.println(F("Sats HDOP Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("          (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
  Serial.println(F("---------------------------------------------------------------------------------------------------------------------------------------"));
  
 Throttle.attach(7);
 Steer.attach(8);
  
  
  // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);

  // Set calibration offset. See HMC5883L_calibration.ino
  compass.setOffset(0, 0);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
    gps_track();
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }

}

void gps_track()
{
    //*******************compasss data ****************************//
   Vector norm = compass.readNormalize();

  // Calculate heading
  double heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
    // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  double declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  // Convert to degrees
 compass_headingDegrees = heading * 180/M_PI; 
  if (gps.location.isValid())
  {  
    double gps_headingDeg;
    double distance_cal;
    double headingRad;
	
    double long1=gps.location.lng() ;//current longitude  from the GPS
    double lat1= gps.location.lat();//current latitude from the GPS
	
    double long2=87.2345  ; //destinantion longitude example
    double lat2=22.1167   ; //destination latitude example
	
    double diflong;
    double diflat;
    double a;
    double c;
    double error;
	
	//processing of data in radians
	
    lat1=radians(lat1);
    long1=radians(long1);
    lat2=radians(lat2);
    long2=radians(long2);
	
	//calculations of the trucking angle
	
     diflong=long1-long2;
    diflat=lat1-lat2;
    headingRad=atan2((sin(diflong)*cos(lat2)),((cos(lat1)*sin(lat2))-(sin(lat1)*cos(lat2)*cos(diflong))));
    gps_headingDeg=(180*headingRad)/3.14159;
    
	//switching to degrees
	
    if(gps_headingDeg>0){
     gps_headingDeg=gps_headingDeg;
    }else{
      gps_headingDeg=gps_headingDeg+360;
    }
      
	 // Figuring out an error between the heading and the bearing
	  
      error =(gps_headingDeg-compass_headingDegrees);
      if(error < -180){
        error=error+360;
      
      }
      if(error>180){
        error =error-360;
     
     
    }
    
    //*******distance calculation
    a=(sin(diflat/2)*sin(diflat/2))+(cos(lat1)*cos(lat2)*(sin(diflong/2)*sin(diflong/2)));
    c=2*atan2(sqrt(a),sqrt(1-a));
    distance_cal=c*6371000.0;// gives in meters
    //////////****************************error calculation
      Serial.print("gps heading");
      Serial.println(gps_headingDeg);
      Serial.print("magnetic heading");
      Serial.println(compass_headingDegrees);
          Serial.print("error");
      Serial.println(error);
        Serial.print("distance");
      Serial.println(distance_cal);
	  
	 // Figuring out where to turn and go
        bool condition=((compass_headingDegrees-10)<gps_headingDeg)&&((compass_headingDegrees+10)>gps_headingDeg);
        if(condition){
         
          fwr();
        }else{
          if(error>10){
            rgt();
          }
          if(error<-10){
            left();
          }
        }
  }
}
void fwr()
{
  Throttle.write(150);//close to max
  Steer.write(90);//middle position
  
  
  
  
}
void left(){
    Throttle.write(0);//min position
    Steer.write(0);//left
  
  
}
void rgt(){
    Throttle.write(0);//min position
    Steer.write(180);//right
  
}


