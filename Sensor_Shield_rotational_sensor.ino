//notes by Dan Davis
//Recommend the Arduno  Sensor Functional Diagram be studied
//Arduino Sensor Shield is used with a rotational sensor and digital LED
//Arduino Sensor Shield does not require a library
// introducing the const int code: declaration of a constant
//equipment: Analog Rotation Sensor DFR 0058, Digital LED, Arduino, IDE serial monitor.
//Sensor Shiled direct connect to the Arduino
//connect the rotational sensor leads G for ground, V for voltage and S for signal A0
//in the same block connect the digital LED G for ground, V for voltage and S for signal A5
//by rotating the  potentiometer, the LED will fade or get bright. Also, see the affect using the serial monitor
//Rotational values : 0 to 1023

//reference https://wiki.dfrobot.com/Analog_Rotation_Sensor_V2__SKU__DFR0058_


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = A5; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(20);
}
