 //motor_pins..................................
#define mright1  3
#define mright2  4
#define mrighten 10
#define mleft1   5
#define mleft2   6
#define mleften  11

 //tcrt_parameters.............................
#define tcrtnum 6

int tcrtstandard[tcrtnum]={200,200,200,200,200,200};
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

Serial.begin(2000000);
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
  /*if(b==1)
{
  
  forward();
  delay(100);
  b++;
}*/
 long int value;
 value=tcrtreading();
 /*if (tcrtvalue[5]==1 && tcrtvalue[4]==0) 
 {
  forward();
  delay(100);
  pause();
  turnright();
  delay(100);
  for(;tcrtvalue[0]!=1;){
    
    turnright();
    value=tcrtreading();
    }
 }*/
 if (tcrtvalue[5]==1) 
 {
  pause();
  turnright();
  delay(100);
  for(;tcrtvalue[0]!=0;){
    
    turnright();
    value=tcrtreading();
    }
  for(;tcrtvalue[0]!=1;){
    
    turnright();
    value=tcrtreading();
    }
    forward();
    delay(20);
 }
 /*else if (tcrtvalue[1]==1 && tcrtvalue[2]==0) 
 {
  forward();
  delay(200);
  pause();
  turnleft();
  delay(100);
  for(;tcrtvalue[0]!=1;){
    
    turnleft();
    value=tcrtreading();
    }
 }*/
 else if (tcrtvalue[1]==1) 
 {
  pause();
  turnleft();
  delay(100);
  for(;tcrtvalue[0]!=0;){
    
    turnleft();
    value=tcrtreading();
    }
  for(;tcrtvalue[0]!=1;){
    
    turnleft();
    value=tcrtreading();
    }
    forward();
    delay(20);
 }

 
 else if(tcrtvalue[4]==1){
      smoothright();
  }
 else if(tcrtvalue[2]==1){
      smoothleft();
  }
 else if(tcrtvalue[0]==1  || tcrtvalue[3]== 1){
     forward();
  }
 else pause();
}  
void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,100);
  delay(1);
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
  analogWrite(mleften, 50);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 50);
  delayMicroseconds(1);
  prevact= 7;  
  }

void turnleft(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 50);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 50);
  delayMicroseconds(1);
  prevact= 8;
  }

void turnright180(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 255);
  prevact= 9;
  }

 void smoothright()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,0);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,50);
  delay(10);                                 // 30 can be changed
  prevact= 10;
 }
 void smoothleft()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,50);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,0); 
  delay(10);// 30 can be changed
  prevact= 11;
 }
