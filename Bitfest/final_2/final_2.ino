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

int tcrtstandard[tcrtnum]={150,150,150,150,150,150};
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
  if(b==1)
{
  
  forward();
  delay(1000);
  b++;
}
  
  value = tcrtreading();
    if(value==111||value==1111||value==11111||value==100111||value==101111||value==111111)
      {
        turnright90();                                        //right90
      }
    else if(value==1||value==10001||value==10010||value==10011||value==1001||value==11001||
    value==1010||value==11010||value==1011||value==11011)
      {
        turnright10();                                          //right60
      }
      
    else if(value==10||value==11)
      {
        turnright60();                                           //right10
      }
    else if(value==100101)
      {
        while(analogRead(A3)<=tcrtstandard[3])
        {
          forwardlong();
        }
        j++;
        if(j!=2)
        turnright120();                                            //right120
        
      }
       if(value == 100100 || value == 100 || value == 100000 || value == 101100 ||
  value == 101110 || value == 100110 || value == 1110  || value == 100011 ||
  value == 1100 || value == 110 || value ==101000 || value == 100010)
      {
        forward();
      }
    else if(value==111100||value==11100||value==111111||value==111110||value==11111||value==11110)
     {
        turnleft90();                                        //left90
     }
    else if(value==10010||value==10000||value==10011||value==10001||value==1001||value==11001||
    value==1010||value==11010||value==1011||value==11011)
      {
        turnleft60();                                             //left60
      }
    else if(value==11000||value==1000)
      {
        turnleft10();                                          //left10
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
    else if(value==0)
        {
          if(a==1)
          {
            forwardlong();
            a++;
          }
          else if(a!=1)
          {
            turnright180();
          }
        }
    
     else forward();
     
}
void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,100);
  delay(10);
  prevact= 1;
  }
void forwardlong(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,100);
  delay(150);
  prevact= 1;
  }
void backward(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten,100);
  prevact = 2;
  }

void pause(){
  digitalWrite(mleft1,LOW);
  digitalWrite(mleft2,LOW);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,LOW);
  }

void turnright60(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 100);
  delay(250);
  prevact= 3;
  }

void turnleft60(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 100);
  delay(250);
  prevact= 4;
  }

void turnright120(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 100);
  delay(620);
  prevact= 5;
  }

void turnleft120(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 100);
  delay(620);
  prevact= 6;
  }

void turnright90(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 100);
  delay(400);
  prevact= 7;
  }

void turnleft90(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 100);
  delay(400);
  prevact= 8;
  }

void turnright180(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, 100);
  delay(900);
  prevact= 9;
  }
void turnleft180(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, 100);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, 100);
  delay(900);
  prevact= 9;
  }

 void turnright10()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,50);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,150);
  delay(100);                                 // 30 can be changed
  prevact= 10;
 }
 void turnleft10()
 {
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,150);
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,50);
  delay(100);                                   // 30 can be changed
  prevact= 11;
 }
