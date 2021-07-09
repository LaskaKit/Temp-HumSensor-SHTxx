# Modul měření teploty a vlhkosti pro SHT40, SHT31, SHT35 a podobné
Vybrat dobré a nejlépe i levné čidlo teploty není jen taky. Chceme kvalitu a zároveň i rozumnou cenu. 
Na základě těchto požadavků vznikl i modul pro měření teploty a vlhkosti, který ale není ledajaký.
Na jedné straně najdete místo pro čidlo SHT31 (a jemu podobném, například SHT30, SHT35) v pouzdru DFN8, 
k těmu pull-up rezistory na I2C sběrnici a blokovací kondenzátor, na druhé straně pak novinku od firmy Sensirion SHT40 v pouzdru DFN4. 
I k němu náleží pull-up rezistory a blokovací kondenzátor. 

Pull-up rezistory máme na obou stranách, ale stačí zapojit je na jedné z nich. Pájení tak bude mnohem jednodušší.

![Desky plošných spojů](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/TempHumModul1cz.JPG)

A proč jsme vybrali zrovna čidla od Sensirion?
Čidla patří mezi hojně používaná, díky svým velmi dobrým vlastnostem, které se ani s časem nijak zvláště nejhorší.
Sensirion zároveň dodává i vlastní knihovny pro svá čidla pro Arduino vývojové desky. 

![Osazené moduly](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/TempHumModul.JPG)

## SHT31
Čidlo teploty a vlhkosti SHT31 se vyrábí v pouzdru DFN8, tedy má 8 plošek na zapájení.
Přesnost SHT31 při měření teploty je +- 0,3 °C pro rozsah měření od -40 °C až do + 90 °C.
Rozlišení je v katalogovém listu uvedeno 0,015 °C a měření trvá po dobu kratší než 2 sekundy.

Pokud vás zajímavá, jak je to s přesností měření teploty v čase, tak tady se ukazuje síla čidel Sensirion. 
Udávaná změna teploty čidla vlivem stárnutí je menší než 0,03 °C za jeden rok. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT31temp.JPG)

Přesnost měření vlhkosti u SHT31 je +- 2 %RH pro rozsah 0 až 90 %RH. Rozlišení je 0,1 %RH a vliv stárnutí čidla se podepíše na nepřesnosti měření pouhým 0,25 %RH za rok. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT31hum.JPG)

Čidla mohou být napájena od 2,4 ž do 5,5V, není tedy třeba přidávat stabilizátor napětí a kazit tak velmi úsporné měření tohoto čidla. 

SHT31 podporuje několik dva typy měření - souvislé, kde spotřeba je během měření 1500 uA a v mezičase pouhých 70 uA a jednorázové měření, kde se po změření čidlo uspí a pak odebírá 2 uA. 

Čidlo má svůj vlastní ohřev, díky jeho použití prodloužíte životnost čidla a měření vlhkosti bude přesnější. 
Výkon ohřevu je od 4.5 mW až do 33 mW. Mějte na paměti, že při použití interního ohřevu je nutné počkat nějakou dobu, než bude možné měřit teplotu a nezanášet si tak chybu do měření. 

Výchozí adresa SHT31 je 0x44.

V tomto repozitáři najdete i vzorkový kód pro SHT31 v kombinaci s vývojovou deskou ESP32 LPkit

## SHT40
Čidlo SHT40 je novinky v portóliu firmy Sensirion, nabízí velmi dobrou přesnost měření, ale jeho cena je výrazně nižší.

SHT40 (popřípadě varianty SHT41 a SHT45) se vyrábějí v pouzdru DFN4, tedy jenom 4 plošky po stranách pouzdra. 

Přesnost měření teploty je +-0,2 °C v rozsahu od 0 °C do 60 °C, rozlišení je pak uvedeno jako 0,1 °C a vliv stárnutí čidla je definován jako menší než 0,03 °C za jeden rok. 

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT40temp.JPG)

Přesnost měření vlhkosti je v katalogovém listu uvedena hodnota +-1,8 %RH, rozlišení je 0,1 %RH a vliv stárnutí součástky je uveden v katalogovém listu jako menší než 0,25 %RH za jeden rok.

![SHT31 - graf teploty](https://github.com/LaskaKit/Temp-HumSensor-SHTxx/blob/main/images/SHT40hum.JPG)

Napájecí napětí čidla se pohybuje v rozsahu od neuvěřitelných 1,08V až do 3,6V. 
Spotřeba během měření se pohybuje okolo 350 uA a ve spánku čidlo SHT40 odebírá pouhých 0,08 uA. 

I SHT40 má vlastní topné tělose, které zpřesňnuje hodnotu měření vlhkosti a je možné jej aktivovat v několik nstaveních.
20mW po dobu 0.1s, 20mW po dobu 1s
a podobně s výkonem 110 mW a 200mW. 

I2C adresa může být 0x44 (SHT40-**A**D1B) nebo 0x45 (SHT40-**B**D1B) podle zakoupeného čidla. 

Vzorový kód pro SHT40 ve spojení s vývojovým kitem ESP32-LPkit také najdete v tomto repozitáři.
