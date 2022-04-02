# Modul for temperature and humidity sensor SHT40
If you are looking for a versatile temperature and humidity module for high quality sensor, you shall check this module which we develop with Sensirion sensor.
On the one-side PCB is a footprint for SHT40 in DFN4 package, pull-up resisitors for I2C bus and decoupling capacitor.</br>

The module is available on https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/

![PCB](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/sht40.JPG)

Why we selected sensors from Sensirion? 
The sensor are used very often, thanks to good parameters and also they are able to work longtime without degradation.
Sensirion also develop own libraries for Arduino evaluation boards, thanks to this, the implementation is much easier. As we mentioned, sensors made by Sensirion are very good and hence you may find a lot of libraries.

## SHT40
The SHT40 sensor is a new sensor in product family of Sensirion. It offers very good accurace and also very low price compared with another sensors.

SHT40 (or another variants like SHT41 and SHT45) are packaged in DFN4, so it measn 4 pads for soldering.

The accuracy of temperature is +-0.2 °C for range from 0 °C to 60 °C, and the resolution is 0.01 °C. The aging of sensor is defined as less than 0.03 °C per year. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/SHT40temp.JPG)
The humidity accuracy is defined as +-1.8 %RH and the resolution is specified as 0.01 %RH. 0.25 % RH is the effect of aging of sensor.

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/SHT40hum.JPG)

The power voltage range is so wide, from 1.08V up to 3.6V. 
The power consumption is around 350 uA during the measurement and 0.08 uA in sleep mode.

SHT40 also have own heater which may increase the accuracy of measured value of humidity. It may be configured by I2C command and set in a few points and times.
20mW for 0.1s, 20mW for 1s
and similar with 110 mW and 200 mW power of heater.

I2C address may be 0x44 (for SHT40-**A**D1B) or 0x45 (for SHT40-**B**D1B) depending of type of SHT40. 

The example code for SHT40 is also available in this repository.

The module is available on https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
