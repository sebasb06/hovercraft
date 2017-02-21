#define BUFF_SIZE 40
char buffer[BUFF_SIZE];

void setup(){
Serial.begin(115200);
Serial3.begin(115200);
}

void loop() {

int i = 0;
while(Serial3.available()) {
buffer[i++] = Serial3.read();
if(i == BUFF_SIZE) break;
}

for(int j = 0; j < i; j++) {
Serial3.print(buffer[j]);
}

}
