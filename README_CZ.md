# Modul teploty a vlhkosti s SHT40
Vybrat dobré a nejlépe i levné čidlo teploty není jen taky. Chceme kvalitu a zároveň i rozumnou cenu. 
Na základě těchto požadavků vznikl i modul pro měření teploty a vlhkosti.</br>
Na jedné straně plošného spoje najdeš čidlo teploty a vlhkosti SHT40 v pouzdru DFN4. </br>
K němu náleží pull-up rezistory pro I2C sběrnici a blokovací kondenzátor. </br>

Modul si můžeš koupit na https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/

![Osazený modul](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/sht40.JPG)

A proč jsme vybrali zrovna čidla od Sensirion?
Čidla patří mezi hojně používaná, díky svým velmi dobrým vlastnostem, které se ani s časem nijak zvláště nehorší.
Sensirion zároveň dodává i vlastní knihovny pro svá čidla pro Arduino vývojové desky. 

## SHT40
Čidlo SHT40 je novinky v portóliu firmy Sensirion, nabízí velmi dobrou přesnost měření, ale jeho cena je výrazně nižší.

SHT40 (popřípadě varianty SHT41 a SHT45) se vyrábějí v pouzdru DFN4, tedy jenom 4 plošky po stranách pouzdra. 

Přesnost měření teploty je +-0,2 °C v rozsahu od 0 °C do 60 °C, rozlišení je pak uvedeno jako 0,01 °C a vliv stárnutí čidla je definován jako menší než 0,03 °C za jeden rok. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/SHT40temp.JPG)

Přesnost měření vlhkosti je v katalogovém listu uvedena hodnota +-1,8 %RH, rozlišení je 0,01 %RH a vliv stárnutí součástky je uveden v katalogovém listu jako menší než 0,25 %RH za jeden rok.

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/img/SHT40hum.JPG)

Napájecí napětí čidla se pohybuje v rozsahu od neuvěřitelných 1,08V až do 3,6V. 
Spotřeba během měření se pohybuje okolo 350 uA a ve spánku čidlo SHT40 odebírá pouhých 0,08 uA. 

I SHT40 má vlastní topné tělose, které zpřesňnuje hodnotu měření vlhkosti a je možné jej aktivovat v několik nstaveních.
20mW po dobu 0.1s, 20mW po dobu 1s
a podobně s výkonem 110 mW a 200mW. 

I2C adresa může být 0x44 (SHT40-**A**D1B) nebo 0x45 (SHT40-**B**D1B) podle zakoupeného čidla. 

Vzorový kód pro SHT40 ve spojení s vývojovým kitem ESP32-LPkit také najdete v tomto repozitáři.

Modul si můžeš koupit na https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/

