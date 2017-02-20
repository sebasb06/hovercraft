void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial3.available()) {
    int inByte = Serial3.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial3.available()) {
    int inByte = Serial3.read();
    Serial.write(inByte);
  }
}
