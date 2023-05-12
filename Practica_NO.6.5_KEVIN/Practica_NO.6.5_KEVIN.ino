
/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Kevin Audiel Solano Torres
 * Fecha: 12/05/2023
 * Proyecto: Termometro
 */

//Librerias
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>  
#define LEDR 3
#define LEDB 4
#define LEDY 5
 
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
LiquidCrystal_I2C LCDKEVIN(0x27,16,2);

byte grados[8] = {
  B01111,
  B01001,
  B01001,
  B01111,
  B00000,
  B00000,
  B00000,
  B00000
};
 
void setup() {
pinMode(LEDR,OUTPUT);
pinMode(LEDB,OUTPUT);
pinMode(LEDY,OUTPUT);
LCDKEVIN.createChar(1, grados);
delay(1000);
Serial.begin(9600);
sensors.begin();   //Se inicia el sensor
LCDKEVIN.begin(16,2); 
LCDKEVIN.init();
LCDKEVIN.backlight();

}
 
void loop() {
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float tempC= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float tempF= sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
LCDKEVIN.setCursor(0,0);
LCDKEVIN.print("TempC");
LCDKEVIN.print(tempC);
LCDKEVIN.print(" C");
LCDKEVIN.setCursor(12,0);
LCDKEVIN.write(1);

LCDKEVIN.setCursor(0,1);
LCDKEVIN.print("TempF");
LCDKEVIN.print(tempF);
LCDKEVIN.print(" F");
LCDKEVIN.setCursor(12,1);
LCDKEVIN.write(1);
delay(100);  

if(sensors.getTempCByIndex(0)>=31){//primero

digitalWrite(LEDR,HIGH);
digitalWrite(LEDY,LOW);
digitalWrite(LEDB,LOW);
}


if(sensors.getTempCByIndex(0)>=16 && sensors.getTempCByIndex(0)<=30){//segundo

digitalWrite(LEDY,HIGH);
digitalWrite(LEDR,LOW);
digitalWrite(LEDB,LOW);
  
}

if(sensors.getTempCByIndex(0)<=15){//tercero

digitalWrite(LEDR,LOW);
digitalWrite(LEDY,LOW);
digitalWrite(LEDB,HIGH);
}





}
