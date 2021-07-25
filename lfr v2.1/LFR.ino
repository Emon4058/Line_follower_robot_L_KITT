 //motor_pins..................................
#define mright1  3
#define mright2  4
#define mrighten 10
#define mleft1   5
#define mleft2   6
#define mleften  11


#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(7, 9, 10, 13, 12);


 //tcrt_parameters.............................
#define tcrtnum 8

//
#define kp 200
#define kd 100
#define stdvalue 2

int tcrtstandard[tcrtnum]={150,150,150,150,150,150,150,150};
int tcrtvalue[tcrtnum];
 //action_parameters...........................

int a=1, b=1;
float value= 0;
float m,p,i,d=0;
 
void setup() {
pinMode(mright1, OUTPUT);
pinMode(mright2, OUTPUT);
pinMode(mrighten, OUTPUT);
pinMode(mleft1, OUTPUT);
pinMode(mleft2, OUTPUT);
pinMode(mleften, OUTPUT);

Serial.begin(9600);
Serial.println("setup_complete");



  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  pinMode(8, OUTPUT);

}


void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  if(analogRead(0) > 150)
      u8g.drawStr( 0, 12, "0");
  else
      u8g.drawStr( 0, 12, "1");
  if(analogRead(1) > 150)
      u8g.drawStr( 30, 12, "0");
  else
      u8g.drawStr( 30, 12, "1");
  if(analogRead(2) > 150)
      u8g.drawStr( 60, 12, "0");
  else
      u8g.drawStr( 60, 12, "1");
  if(analogRead(3) > 150)
      u8g.drawStr( 0, 30, "0");
  else
      u8g.drawStr( 0, 30, "1");
  if(analogRead(4) > 150)
      u8g.drawStr( 15, 30, "0");
  else
      u8g.drawStr( 15, 30, "1");
  if(analogRead(5) > 150)
      u8g.drawStr( 30, 30, "0");
  else
      u8g.drawStr( 30, 30, "1");
  if(analogRead(6) > 150)
      u8g.drawStr( 45, 30, "0");
  else
      u8g.drawStr( 45, 30, "1");
  if(analogRead(7) > 150)
      u8g.drawStr( 60, 30, "0");
  else
      u8g.drawStr( 60, 30, "1");
}




void loop() {





  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  //delay(50);





  
  /*if(b==1)
{
  
  forward();                            // starting time
  delay(100);
  b++;
}*/
 long int value;
 value=tcrtreading();

/* if (tcrtvalue[7]==1) 
 {
  pause();
  turnright();
    delay(100);   
  for(;tcrtvalue[1]!=0;){             //starting rotate
    
    turnright();
    value=tcrtreading();
    }
  for(;tcrtvalue[1]!=1;){                //continue & termination
    
    turnright();
    value=tcrtreading();
    }
    forward();
    delay(20);
 }
 
 else if (tcrtvalue[3]==1) 
 {
  pause();
  turnleft();
  delay(100);   
  for(;tcrtvalue[1]!=0;){
    
    turnleft();
    value=tcrtreading();
    }
  for(;tcrtvalue[1]!=1;){
    
    turnleft();
    value=tcrtreading();
    }
    forward();
    delay(20);
 }

 
 else if(tcrtvalue[6]==1 || tcrtvalue[4]==1){ */ 
      m=smooth();
      motor(m);
 /*  }
 
else if(tcrtvalue[1]==1  || tcrtvalue[5]== 1){
     forward();
  }
 // else pause();
}  
void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 150);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,150);
  delay(1);
  }*/
}
void pause(){
  digitalWrite(mleft1,LOW);
  digitalWrite(mleft2,LOW);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,LOW);
  }

void turnright(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten,255);
  delayMicroseconds(1);  
  }

void turnleft(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 255);
  delayMicroseconds(1);
  }

void turnright180(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 255);
  }
  
