//motor_pins..................................
#define mright1  3
#define mright2  4
#define mrighten 10
#define mleft1   5
#define mleft2   6
#define mleften  11
int j=0;
int leftbasespeed = 255;
int rightbasespeed = 255; 



//tcrt_parameters.............................
#define tcrtnum 6

int tcrtstandard[tcrtnum]={250, 240, 250, 350, 300, 250};
int tcrtvalue[tcrtnum]={1, 0, 0, 1, 0, 0};

 //action_parameters...........................

int prevact, a=1, b=1;
long int value= 0;

 
void setup() {
pinMode(mright1, OUTPUT);
pinMode(mright2, OUTPUT);
pinMode(mrighten, OUTPUT);
pinMode(mleft1, OUTPUT);
pinMode(mleft2, OUTPUT);
pinMode(mleften, OUTPUT);

Serial.begin(38400);
Serial.println("setup_complete");

}

long int tcrtreading(){
  long int sumvalue = 0 ;
  for(int i=0;i<tcrtnum;i++){
    if(analogRead(i) > tcrtstandard[i]){
      tcrtvalue[i]=0;
      }
    else{
      tcrtvalue[i]=1;
      }

    sumvalue= ((sumvalue*10)+tcrtvalue[i]);
    
    Serial.print(analogRead(i));
    Serial.print(" ");
    }
    Serial.print(sumvalue);
    Serial.println(" ");
  return sumvalue;
}

void loop() {
  value=tcrtreading();
  if(b==1)
{
  b++;
  forward();
  delay(450);
}
else if(value==110100){
    digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 200);
  delay(700);
  forward();
  b==100;
  }
else if(tcrtvalue[5]==1 && tcrtvalue[4]==1)
{
  turnright90();
  pause();
  forward();
  delay(200);
}
else if(tcrtvalue[1]==1 && tcrtvalue[2]==1)
{
  if(b==100)
  {
      digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 200);
  delay(275);
  forward();
  }
  else
  {turnleft90();
  pause();
  forward();
  delay(200);}
}

 
else if(value==110100)
      {
        while(analogRead(A3)<=tcrtstandard[3])
        {
          forwardlong();
        }
        j++;
        if(j!=2)
        turnleft120();                                             //left120
      }
      else if(value==10||value==11)
      {
        turnright60();                                           //right10
      }
else forward();


}
void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,255);
  delay(10);
  prevact= 1;
  }
void forwardlong(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,255);
  delay(500);
  prevact= 1;
  }

void pause(){
  digitalWrite(mleft1,LOW);
  digitalWrite(mleft2,LOW);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,LOW);
  }

 

void turnright90(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 200);
  delay(460);
  prevact= 7;
  }

void turnleft90(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 200);
  delay(460);
  prevact= 8;
  }



 void turnright10()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,100);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,255);
  delay(50);                                 // 30 can be changed
  prevact= 10;
 }
 void turnleft10()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,255);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,100);
  delay(500);                                   // 30 can be changed
  prevact= 11;
 }

 void turnright60(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 200);
  delay(250);
  prevact= 3;
  }

void turnleft60(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 200);
  delay(250);
  prevact= 4;
  }

void turnright120(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 200);
  delay(620);
  prevact= 5;
  }

void turnleft120(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 200);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 200);
  delay(620);
  prevact= 6;
  }
