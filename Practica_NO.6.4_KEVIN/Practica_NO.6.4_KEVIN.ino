/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Kevin Audiel Solano Torres 
 * Fecha: 11 DE Mayo
 * Proyecto: Parqueo
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCDKEVIN(0x27,16,2);


const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;


byte cuadro[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};



void setup (){
LCDKEVIN.begin(16,2); 
LCDKEVIN.createChar(1,cuadro);  
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
LCDKEVIN.init();
LCDKEVIN.backlight();
Serial.begin(9600);
}



void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print(String(distance));
  Serial.println(" cm");
  delay(400);

  
  
if(distance>=31&&distance<=81){//if para la distancia "considerada libre"

LCDKEVIN.clear();
LCDKEVIN.setCursor(0,0);
LCDKEVIN.print("       50     ");
delay(250);
LCDKEVIN.setCursor(0,1);
LCDKEVIN.print("     libre    "); 
LCDKEVIN.setCursor(4,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(5,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(6,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(9,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(10,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(11,0);
LCDKEVIN.write(1);
 


 }
  
  
if(distance>=11&&distance<=30){//if para la distancia "considerada libre"

LCDKEVIN.clear();
LCDKEVIN.setCursor(0,0);
LCDKEVIN.print("       30     ");
delay(250);
LCDKEVIN.setCursor(0,1);
LCDKEVIN.print("     CUIDADO    "); 
LCDKEVIN.setCursor(2,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(3,0);
LCDKEVIN.write(1);    
LCDKEVIN.setCursor(4,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(5,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(6,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(9,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(10,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(11,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(12,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(13,0);
LCDKEVIN.write(1);
  


 }
  
if(distance>=1&&distance<=10){//if para la distancia "considerada libre"

LCDKEVIN.clear();
LCDKEVIN.setCursor(0,0);
LCDKEVIN.print("       10     ");
delay(250);
LCDKEVIN.setCursor(0,1);
LCDKEVIN.print("      Alto    "); 
LCDKEVIN.setCursor(0,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(1,0);
LCDKEVIN.write(1);    
LCDKEVIN.setCursor(2,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(3,0);
LCDKEVIN.write(1);    
LCDKEVIN.setCursor(4,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(5,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(6,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(9,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(10,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(11,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(12,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(13,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(14,0);
LCDKEVIN.write(1);
LCDKEVIN.setCursor(15,0);
LCDKEVIN.write(1);
  

 }
  
  

  
}
