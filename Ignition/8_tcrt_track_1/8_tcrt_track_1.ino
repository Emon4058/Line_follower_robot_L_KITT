 //motor_pins..................................
#define mright1  3
#define mright2  4
#define mrighten 10
#define mleft1   5
#define mleft2   6
#define mleften  11

int leftbasespeed = 255;
int rightbasespeed = 255; 

 //tcrt_parameters.............................
#define tcrtnum  8

int tcrtstandard[tcrtnum]={/*300, 300, 320, 250, 250, 180,100,100*/};
int tcrtvalue[tcrtnum]={0, 1, 0, 0, 0, 1, 0, 0};

 //action_parameters...........................

int prevact;
long int value= 0;

 
void setup() {
pinMode(mright1, OUTPUT);
pinMode(mright2, OUTPUT);
pinMode(mrighten, OUTPUT);
pinMode(mleft1, OUTPUT);
pinMode(mleft2, OUTPUT);
pinMode(mleften, OUTPUT);

Serial.begin(9600);
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
    Serial.print(" ");
  return sumvalue;
}

void loop() {
  value = tcrtreading();
    Serial.println(value);
    
    //code for M
    
   /*if(value==1100100||value==11000100)
    {
      while(tcrtvalue[3]==0&&tcrtvalue[4]==0&&tcrtvalue[5]==1&&tcrtvalue[6]==0&&tcrtvalue[7]==0)
      {
      forward();
      }
      if(value%100000>100)
      turnright();
      else if((value%100000)<100)
      turnleft();
    }*/
    
  else forward();
  
}

void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,255);
  prevact= 1;
  }

void pause(){
  digitalWrite(mleft1,LOW);
  digitalWrite(mleft2,LOW);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,LOW);
  delay(50);
  prevact= 2;
  }

void turnright(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,HIGH);
  analogWrite(mrighten, 255);
  delay(10);
  prevact= 3;
  }

void turnleft(){
  digitalWrite(mleft1,LOW);
  digitalWrite(mleft2,HIGH);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 255);
  delay(10);
  prevact= 4;
  }
void turnright180(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,HIGH);
  analogWrite(mrighten, 255);
  delay(160);
  
  prevact= 5;
  }
void turnright10(){
  turnright();
  delay(250);
  while(analogRead(A1)!=1)
   {turnright();}
   forward();
   delay(50);
  prevact=6;
}
void turnleft10(){
  turnleft();
  delay(250);
  while(analogRead(A1)!=1)
   {turnleft();}
   forward();
   delay(50);
  prevact=7;
}
