/*
* This example code for Temperature and Humidity SHTxx module
* is used with ESP32 LPkit board.
* ESP32-LPkit reads temperature and humidity from SHT40 sensor 
* and sends every second through UART
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2021
*
* Libraries
* https://github.com/adafruit/Adafruit_SHT4X
*/
 
#include <Wire.h>
#include "Adafruit_SHT4x.h"
 
Adafruit_SHT4x sht4 = Adafruit_SHT4x();
 
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  while (!Serial) 
  {
    ; // wait for serial
  }
 
  if (! sht4.begin()) 
  {
    Serial.println("SHT4x not found");
    Serial.println("Check the connection");
    while (1) delay(1);
  }
 
  sht4.setPrecision(SHT4X_HIGH_PRECISION); // highest resolution
  sht4.setHeater(SHT4X_NO_HEATER); // no heater
 
}
 
void loop() {
  sensors_event_t humidity, temp; // temperature and humidity variables
 
  sht4.getEvent(&humidity, &temp);
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degC");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
 
  delay(1000);
}
