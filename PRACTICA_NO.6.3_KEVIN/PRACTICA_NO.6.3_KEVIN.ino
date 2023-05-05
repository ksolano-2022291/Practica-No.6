/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Kevin Audiel Solano Torres 
 * Fecha: 05 DE Mayo
 * Proyecto: Alarma de distancia
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCDKEVIN(0x27,16,2);
#define BUZZER A1
#define LED1 2
#define LED2  3
#define LED3  4
#define LED4  5
#define LED5  6
#define LED6  7
#define LED7  8
#define LED8  9
#define LED9  10
#define LED10 A0


int Do=261;
int Re=293; 
int Mi=329; 
int Fa=349; 
int Sol=392;
int La=440; 
int Si=493; 
int duracion=1000;
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(BUZZER,OUTPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);
pinMode(LED6,OUTPUT);
pinMode(LED7,OUTPUT);
pinMode(LED8,OUTPUT);
pinMode(LED9,OUTPUT);
pinMode(LED10,OUTPUT);
LCDKEVIN.init();
LCDKEVIN.backlight();
Serial.begin(9600);

}


void loop() {
  
  
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
  
 
  
  
  
 if(distance>=46 && distance <=60){
  
  digitalWrite(LED1,LOW); 
  digitalWrite(LED2,LOW); 
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW); 
  digitalWrite(LED5,LOW); 
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW); 
  digitalWrite(LED8,LOW); 
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  LCDKEVIN.clear();
  LCDKEVIN.setCursor(0,0);
  LCDKEVIN.print("Fuera de alcance");
  tone(BUZZER,Do,1000);
  delay(500);
  }
  
  
  if(distance>=31 && distance <=45){
  digitalWrite(LED1,HIGH); 
  digitalWrite(LED2,HIGH); 
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH); 
  digitalWrite(LED5,LOW); 
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW); 
  digitalWrite(LED8,LOW); 
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  LCDKEVIN.clear();
  LCDKEVIN.setCursor(0,0);
  LCDKEVIN.print("persona");
  LCDKEVIN.setCursor(0,1);
  LCDKEVIN.print("acercandose");  
  tone(BUZZER,Re,1000);
  delay(500);
  }
  
   
  if(distance>=16 && distance <=30){
  digitalWrite(LED1,HIGH); 
  digitalWrite(LED2,HIGH); 
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH); 
  digitalWrite(LED5,HIGH); 
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH); 
  digitalWrite(LED8,LOW); 
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  LCDKEVIN.clear();
  LCDKEVIN.setCursor(0,0);
  LCDKEVIN.print("Cuidado,");
  delay(500);
  LCDKEVIN.setCursor(0,1);
  LCDKEVIN.print("espacio privado");  
  tone(BUZZER,Mi,5000);
  delay(500);
  }
  
   if(distance>=6 && distance <=15){
  digitalWrite(LED1,HIGH); 
  digitalWrite(LED2,HIGH); 
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH); 
  digitalWrite(LED5,HIGH); 
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH); 
  digitalWrite(LED8,HIGH); 
  digitalWrite(LED9,HIGH);
  digitalWrite(LED10,HIGH);
  LCDKEVIN.clear();
  LCDKEVIN.setCursor(0,0);
  LCDKEVIN.print("invadiendo");
  delay(500);
  LCDKEVIN.setCursor(0,1);
  LCDKEVIN.print("espacio privado");  
  tone(BUZZER,Mi,10000);
  delay(500);
  }
  
  
  
  
}
