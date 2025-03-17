/*
* This example code for Refresh Temperature and Humidity SHT4x module
*
* Made by (c) laskakit.cz 2025
*
*/
 
 
#include <Arduino.h>
#include <SensirionI2cSht4x.h>
#include <Wire.h>

SensirionI2cSht4x sht4x;

uint16_t error;
char errorMessage[256];
float temperature;
float humidity;

#define PIN_ON 47  //S3-DevKit
//#define PIN_ON 4  //C3-LPKit


void setup() {
    pinMode(PIN_ON, OUTPUT);
    digitalWrite(PIN_ON, HIGH);
    
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    // Wire begin on next pins:
    Wire.begin(42,2); //(SDA, SCL)  on S3-Devkit
    //Wire.begin(8, 10);  //(SDA, SCL)  on C3-LPKit
    delay(250);
    
    sht4x.begin(Wire, 0x44);

    uint32_t serialNumber;
    error = sht4x.serialNumber(serialNumber);
    if (error) {
        Serial.print("Error trying to execute serialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("Serial Number: ");
        Serial.println(serialNumber);
        delay(1000);
        error = sht4x.measureHighPrecision(temperature, humidity);
    }

    while (humidity >= 5.0){
  
      if (temperature >= 125.0){
        delay(100);
      }
      error = sht4x.activateHighestHeaterPowerLong(temperature, humidity);
      
      if (error) {
          Serial.print("Error trying to execute measureHighPrecision(): ");
          errorToString(error, errorMessage, 256);
          Serial.println(errorMessage);
      } else {
          Serial.print("Temperature: ");
          Serial.print(temperature);
          Serial.print("°C ");
          Serial.print("Humidity: ");
          Serial.print(humidity);
          Serial.println("%RH");
      }
    }

    Serial.println("Senzor refresh done");
}

void loop() {
  delay(1000);
  error = sht4x.measureHighPrecision(temperature, humidity);
  if (error) {
      Serial.print("Error trying to execute measureHighPrecision(): ");
      errorToString(error, errorMessage, 256);
      Serial.println(errorMessage);
  } else {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print("°C ");
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.println("%RH");
  }
}
