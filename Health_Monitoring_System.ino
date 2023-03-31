/*Task 3 */
/* Health Monitoring System*/
/*Problem: This system allows users to keep track of their body
vitals like blood pressure, sugar level,
and heartbeat and remotely send
the data to healthcare professionals.
*/




#include<Wire.h>
#include<MAX30105.h>
#include<HeartRate.h>


MAX30105 particleSensor;

void setup()
{
  Serial.begin(9600);
  particleSensor.begin(Wire, I2C_SPEED_FAST);
  particleSensor.setup(); 
  particleSensor.setPulseAmplitudeRed(0x0A); 
  particleSensor.setPulseAmplitudeGreen(0); 
}

void loop()
{
  int32_t irValue = particleSensor.getIR();
  int32_t redValue = particleSensor.getRed();
  int HeartRate = getHeartRate();
  float SpO2 = getSpO2();
  
  Serial.print("Heart Rate: ");
  Serial.println(HeartRate);
  Serial.print("SpO2: ");
  Serial.println(SpO2);
  delay(500);
}
