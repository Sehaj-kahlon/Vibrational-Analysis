#include <EEPROM.h>

#include <Wire.h>  // Include the Wire library for I2C communication

int ADXL345 = 0x53; // I2C address of the ADXL345 accelerometer
float X_out, Y_out, Z_out; // Variables to store accelerometer readings

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  Wire.begin(); // Initialize the Wire library (I2C)

  // Begin communication with the ADXL345
  Wire.beginTransmission(ADXL345); 
  Wire.write(0x2D); // Write to the Power Control register
  Wire.write(8); // Set the measurement mode (turn on the device)
  Wire.endTransmission(); // End transmission to the device
  delay(10); // Wait for a short period for the device to initialize
}

void loop() {
  
  // Start communication with the ADXL345
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Set the register pointer to the Data Register (starting with X-axis)
  Wire.endTransmission(false); // End transmission but keep the connection open

  // Request 6 bytes of data from the ADXL345 (X, Y, Z axis data)
  Wire.requestFrom(ADXL345, 6, true); 

  // Read and combine two bytes for X-axis value
  X_out = (Wire.read() | Wire.read() << 8); // Combine low and high byte for X-axis
  X_out = X_out / 256; // Scale down the value

  // Read and combine two bytes for Y-axis value
  Y_out = (Wire.read() | Wire.read() << 8); // Combine low and high byte for Y-axis
  Y_out = Y_out / 256; // Scale down the value

  // Read and combine two bytes for Z-axis value
  Z_out = (Wire.read() | Wire.read() << 8); // Combine low and high byte for Z-axis
  Z_out = Z_out / 256; // Scale down the value

  // Print accelerometer readings to the Serial Monitor
  Serial.print("Time_Stamp= "); 
  Serial.print(millis());
  Serial.print(" Xa= "); 
  Serial.print(X_out); 
  Serial.print("   Ya= "); 
  Serial.print(Y_out); 
  Serial.print("   Za= "); 
  Serial.println(Z_out); 
}
