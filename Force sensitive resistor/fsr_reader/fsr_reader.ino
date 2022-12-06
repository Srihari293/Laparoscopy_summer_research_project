// Initializations:
// Pins 
int FSRpin = A0;

// Variables
float value = 0;
float voltage = 0;
float resistance = 0;
float conductance = 0;
float force = 0;
float V_in = 5000; // Input Voltage (mV)
float R_m = 10000;   // Measurement Resistor (ohms)

void setup(void) {
  Serial.begin(9600);
}

void loop() {

  //Obtain analog reading of the voltage from pin A0 (FSR)
  value = analogRead(FSRpin);
  Serial.print("Analog reading from FSR = ");
  Serial.println(value);

  // Value lies between 0 and 782. So we have to remap it.
  // Map analog value to obtain Vo in mV
  voltage = map(value, 0, 800, 0., 5000.);

  if (voltage == 0) {
    Serial.println("No force applied");
    delay(1000);
    return;
  }

  Serial.print("Vo = ");
  Serial.print(voltage);
  Serial.println(" mV ");

  //Calculate resistance using voltage divider equation
  //R_fsr = [(Vin*R)/Vo] - R // (ohms)
  resistance = ((V_in * R_m) / voltage) - R_m;
  Serial.print("Resistance = ");
  Serial.print(resistance);
  Serial.println(" ohms");

  //Calculate conductance in micro mho(1/R)
  conductance = 1000. / resistance;                     //Convert to kilo mhos (or) kilo Siemens(kS)
  //  conductance = 1./resistance;
  Serial.print("Conductance = ");
  Serial.print(conductance);
  Serial.println(" kS");


  //  //Use the FSR resistance vs. force graphs to estimate the force
  //  if (conductance <= 1000) {
  //    force = conductance / 80;
  //  }
  //  if(conductance > 1000) {
  //    force = (conductance - 1000) / 30;
  //  }
  //
  //  Serial.print("Force =  ");
  //  Serial.print(force);
  //  Serial.println(" N ");
  //

  // Force calculation
  // Mathematical model: force = (3.63181 * 10^6 * (conductance*conductance)) + (97423.2*conductance) + 13.0807;
  force = (3.63181 * 1e7 * (conductance * conductance)) + (97423.2 * conductance) + (13.0807);
  Serial.print("Force =  ");
  Serial.print(force);
  Serial.println(" g ");
  Serial.println("--------------------");
  delay(1000);
}
