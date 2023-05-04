/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico:  EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: lcd aforo
   alumno:Kevin Audiel Solano Torres
   Fecha: 04 de Mayo
*/


#include <LiquidCrystal.h>
#define RS 6
#define ENABLE 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define BUZZER  10
int DO=659;
int conta=0;
int sumador=0;
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;

LiquidCrystal LCDKEVIN(RS,ENABLE,D4,D5,D6,D7);


byte calaveracerrada[8] = {
  B00000,
  B01110,
  B10101,
  B10101,
  B10101,
  B01110,
  B01110,
  B00000
};


byte calavera[8] = {
  B00000,
  B01110,
  B10101,
  B10101,
  B10101,
  B01110,
  B01010,
  B00100
};


void setup(){
  Serial.begin(9600);
  LCDKEVIN.begin(16,2);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(BUZZER,OUTPUT);
  LCDKEVIN.createChar(1,calaveracerrada);
  LCDKEVIN.createChar(2,calavera);
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

   
   if(distance>=5 && distance <11)
   {
   conta++;
   LCDKEVIN.setCursor(0,0);
   LCDKEVIN.print("Contador aforo");
   LCDKEVIN.setCursor(0,1);
   LCDKEVIN.print(sumador++);
   delay(500);
    }
  
  if((sumador)>=16)
    {
    LCDKEVIN.setCursor(0,0);
    LCDKEVIN.print("                ");
    LCDKEVIN.setCursor(0,1);
    LCDKEVIN.print("                ");
    sumador=16;
    tone(BUZZER,DO,500);
    delay(500);
    LCDKEVIN.setCursor(0,0);
    LCDKEVIN.write(1);
    delay(250);
    LCDKEVIN.setCursor(0,0);
    LCDKEVIN.write(2);
    delay(250); 
    }
 
}
