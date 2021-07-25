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


#define tr1 2
#define ec1 7
#define tr2 8
#define ec2 9
long ti1;
int d1;
long ti2;
int d2;
int d=1;
int c;

int prevact, a=1, b=1;
long int value= 0;

 
void setup() {
pinMode(mright1, OUTPUT);
pinMode(mright2, OUTPUT);
pinMode(mrighten, OUTPUT);
pinMode(mleft1, OUTPUT);
pinMode(mleft2, OUTPUT);
pinMode(mleften, OUTPUT);
pinMode(tr1, OUTPUT);
  pinMode(ec1, INPUT);
  pinMode(tr2, OUTPUT);
  pinMode(ec2, INPUT);

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

void loop() {if(b==1){
  digitalWrite(tr1, LOW);
 delayMicroseconds(2);
 digitalWrite(tr1, HIGH);
 delayMicroseconds(10);
 digitalWrite(tr1, LOW);
 ti1=pulseIn(ec1,HIGH);
 d1=ti1*(0.034/2);

 if(d1>1 && d1<10){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 255);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,255);
  delay(700);
  b=2;
  }
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
 else if (value==0){
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
 else forward();
 }







 else if (b=2){
 digitalWrite(tr2, LOW);
 delayMicroseconds(2);
 digitalWrite(tr2, HIGH);
 delayMicroseconds(10);
 digitalWrite(tr2, LOW);
 ti2=pulseIn(ec2,HIGH);
 d2=ti2*(0.034/2);
  if(d=1){if(d2>1 && d2<30){
    c=d2;
    d++;
    }}

    if(d=2){
      for(;;){
        if(d2>c){
          smoothright();
          }
         else if(d2<c){
          smoothleft();
         }else
          forward();
          value=tcrtreading();
          if(value!=0){
          break;
          b=3;
          }
        }
      
      }
value=tcrtreading();

 if (tcrtvalue[1]==1) 
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
  else if (tcrtvalue[5]==1) 
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
 else if (value==0){
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
 else forward();







      
  
  
  
  
  }


  if(b=3){
    value=tcrtreading;

 if(tcrtvalue[4]==1){
      smoothright();
  }
 else if(tcrtvalue[2]==1){
      smoothleft();
  }
 else if(tcrtvalue[0]==1  || tcrtvalue[3]== 1){
     forward();}
   if (tcrtvalue[1]==1) 
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
    
    
    
    
    
    
    
    
    
    
    
    
    }
}  
void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 170);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,170);
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
  analogWrite(mrighten,50);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,200);
  delay(10);                                 // 30 can be changed
  prevact= 10;
 }
 void smoothleft()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,200);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,50); 
  delay(10);// 30 can be changed
  prevact= 11;
 }
