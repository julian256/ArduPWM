void setup() {
  TCCR2A = TCCR2A | 0x30;
  TCCR2B = TCCR2B & 0xF8 | 0x01;
  analogWrite(11, 117);
  analogWrite(3, 137);
  Serial.begin(9600);
}

byte deciVolts = 0;
byte pulseWidth = 0;

void loop() {
  deciVolts = analogRead(A1) / 16 + 89;
  Serial.print(deciVolts);
  Serial.print(" ");
  if (deciVolts < 135)
  {
    if (pulseWidth != 255) pulseWidth++;
  }
  if (deciVolts > 135)
  {
    if (pulseWidth != 0) pulseWidth--;
  }
  Serial.println(pulseWidth);
  analogWrite(9, pulseWidth);
  delay(10);
} 
