# Modul for temperature and humidity sensor like SHT40, SHT31, SHT35 and similar
If you are looking for a versatile temperature and humidity module for hihg quality sensor, you shall check this module which we develop for Sensirion sensors.
On the TOP side, there is a footprint for SHT31 (and similar like SHT30, SHT35) with DFN8 package. On the same side of PCB, there are pull-up resistors and decoupling capacitor.
On the BOTTOM side, there is a footprint for SHT40 in DFN4 package. There are also pull-up resisitors and decoupling capacitor.

Pull-up resistors are on the both side and the reason is easier soldering.

![PCB](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/TempHumModul1.JPG)

Why we selected sensors from Sensirion? 
The sensor are used very often, thanks to good parameters and also they are able to work longtime without degradation.
Sensirion also develop own libraries for Arduino evaluation boards, thanks to this, the implementation is much easier. As we mentioned, sensors made by Sensirion are very good and hence you may find a lot of libraries.

![Assembled PCB](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/TempHumModul.JPG)

## SHT31
The package of SHT31 is DFN8, so there are 8 pads for soldering. 
The accuracy for measurement of temperature is +- 0.3 °C for measured range from -40 °C up to + 90 °C.
The resolution is 0.015 °C what is mentioned in datasheet. The time for measurement takes less than 2 seconds.

If you are interest in longtime duration, the accuracy will get worse only by 0,03 °C per year. 

![SHT31 - temperature chart](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT31temp.JPG)

The accuracy for measurement of humidity for SHT31 is +- 2 %RH for a range from 0 to 90 %RH. The resolution is 0,1 %RH and the effect of aging is only 0,25 %RH per year. 

![SHT31 - humidity chart](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT31hum.JPG)

The sensor may be powered from 2.4V up to 5.5V so it is not needed to design also low-drop voltage regulator, because the range of power votlage is so wide.

SHT31 supports a few types of measurement - continous, where the power consumption is 1500 uA during the measurement, out of this time the power consumption is only 70 uA.
The second type of measurement is single-shot measurement where the sensor is going to sleep after the measuring of temperature and humidity. In this case the current is only 2uA 

The sensor includes own heater which you may control by I2C register. If you use it, and we recommend it, you extend the product life and the measured value will be more precise mainly for humidity.
The power of heater may be set in a few points from 4.5 mW up to 33 mW. 
Please, keep in mind, if you use heater, you have to wait between heating and measuring of temperature because the sensor has to be spontaneously cooled . Otherwise you add the error of measured value.

The default value is 0x44 for SHT31.

In this repository, you also find the example code how to use it with our ESP32 LLPkit evaluation board.

## SHT40
The SHT40 sensor is a new sensor in product family of Sensirion. It offers very good accurace and also very low price compared with another sensors.

SHT40 (or another variants like SHT41 and SHT45) are packaged in DFN4, so it measn 4 pads for soldering.

The accuracy of temperature is +-0,2 °C for range from 0 °C to 60 °C, and the resolution is 0,1 °C. The aging of sensor is defined as less than 0.03 °C per year. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT40temp.JPG)
The humidity accuracy is defined as +-1,8 %RH and the resolution is specified as 0,1 %RH. 0.25 % RH is the effect of aging of sensor.

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT40hum.JPG)

The power voltage range is so wide, from 1.08V up to 3.6V. 
The power consumption is around 350 uA during the measurement and 0.08 uA in sleep mode.

SHT40 also have own heater which may increase the accuracy of measured value of humidity. It may be configured by I2C command and set in a few points and times.
20mW for 0.1s, 20mW for 1s
and similar with 110 mW and 200 mW power of heater.

I2C address may be 0x44 (for SHT40-**A**D1B) or 0x45 (for SHT40-**B**D1B) depending of type of SHT40. 

The example code for SHT40 is also available in this repository.
