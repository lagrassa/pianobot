int time=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(time);
  time++;
}
