// 

int sensorValue = 0;
float valueVolt = 0.0;
float tempC = 0.0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {

  sensorValue = analogRead(A0);
  valueVolt = (3.3*sensorValue)/1024;
  tempC = 100.0*valueVolt;           // LM35
  //tempC = 100.0*valueVolt - 50.0;  // TMP36

  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(500);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);                      // Wait for two seconds (to demonstrate the active low LED)

  Serial.print(sensorValue);
  Serial.print("  ");
  Serial.print(valueVolt);
  Serial.print("  ");
  Serial.println(tempC);

}
