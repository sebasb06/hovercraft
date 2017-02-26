#define BUFF_SIZE 40
char imu_buffer[BUFF_SIZE];

void IMU_setup()
{
   imuSerial.begin(imuBaud);
}

String imu_output; // holds output from imu chip

void IMU_sloop()
{
    readFromIMU();
}

void readFromIMU()
{
  int i = 0;
  while(imuSerial.available()) {
    imu_buffer[i++] = imuSerial.read();
    if(i == BUFF_SIZE) 
    {
      imu_output = imu_buffer;
      break;
    } //if 
  } // while


 // for (int j = 0; j < i ; j++)
 // Serial.print (imu_buffer[j]);
  writeData ("IMU", imu_output);
  


}

