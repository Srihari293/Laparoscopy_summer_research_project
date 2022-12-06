// Initializations:
// Pins
int FSRpin = A0;

// Variables
float value = 0;
float voltage = 0;

void setup(void) {
  Serial.begin(9600);
}

void loop() {

  //Obtain analog reading of the voltage from pin A0 (FSR)
  value = analogRead(FSRpin);

  // Value lies between 0 and 782. So we have to remap it. Map analog value to obtain Vo in mV
  voltage = map(value, 0, 785, 1., 5000.);

  if (value > 0 && voltage > 0) {
//    Serial.print(value);
//    Serial.print(",");
    Serial.println(voltage);
    delay(250);
  }
}
