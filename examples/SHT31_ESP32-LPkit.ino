/*
* This example code for Temperature and Humidity SHTxx module
* is used for ESP32 LPkit.
* ESP32-LPkit reads temperature and humidity from SHT31 sensor 
* and sends every second through UART
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskarduino.cz 2021
*
*	Potrebne knihovny:
*	https://github.com/adafruit/Adafruit_SHT31
*/

#include <WiFi.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  while (!Serial) 
  {
    ; // wait for serial port
  }

  if (! sht31.begin(0x45))  // alternatively 0x44, depends on ADDR pin
  {
    Serial.println("SHT31 not found");
    Serial.println("Check the connection");
    while (1) delay(1);
  }

}

void loop() {
  float temperature = sht31.readTemperature();
  float humidity = sht31.readHumidity(); 

  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" degC");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% rH");

  delay(1000);
}
