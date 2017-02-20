#define BUFF_SIZE 40
char buffer[BUFF_SIZE];

void setup(){
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() {

int i = 0;
while(Serial1.available()) {
buffer[i++] = Serial1.read();
if(i == BUFF_SIZE) break;
}

for(int j = 0; j < i; j++) {
Serial.print(buffer[j]);
}

}
