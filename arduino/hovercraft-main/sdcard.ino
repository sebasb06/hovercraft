/*
 * Write data to SD card
 */
void writeData (String data)
{
  data = "Data: " + data;
  Serial.println (data);

  if (1 || GPS.fix == 1)
  {
    mySensorData = SD.open("Coords.txt", FILE_WRITE); //Open file on SD card for writing
    mySensorData.println(data); //Write first NMEA to SD card
    mySensorData.close();  //Close the file
  }
}

