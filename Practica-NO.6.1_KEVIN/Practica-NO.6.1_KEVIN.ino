/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico:  EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: lcd
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


LiquidCrystal LCDKEVIN(RS,ENABLE,D4,D5,D6,D7);


void setup(){

  LCDKEVIN.begin(16,2);
  
}


void loop(){


  LCDKEVIN.setCursor(0,0);
  LCDKEVIN.print("Kevin Solano ");
  LCDKEVIN.setCursor(0,1);
  LCDKEVIN.print("2022291");
}
