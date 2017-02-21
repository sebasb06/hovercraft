#define BUFF_SIZE 40
char imu_buffer[BUFF_SIZE];

void IMUsetup()
{
   imuSerial.begin(115200);
}

String imu_output; // holds output from imu chip

void IMUloop()
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
    }
  }

  
  
  writeData ("IMU", imu_output);
  
 // for(int j = 0; j < i; j++) {
  //Serial.print(buffer[j]);
  //}

}

