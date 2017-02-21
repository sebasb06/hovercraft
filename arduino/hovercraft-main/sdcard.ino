/*
 * Write data to SD card
 */
void writeData (String source, String data)
{
  
  //data = source + ": " + data;
  Serial.println ("@" + source);
  Serial.println (data);
  Serial.println ("");

  if (1 || GPS.fix == 1)
  {
    mySensorData = SD.open("output.txt", FILE_WRITE); //Open file on SD card for writing
    mySensorData.println(data); //Write first NMEA to SD card
    mySensorData.close();  //Close the file
  }
}

