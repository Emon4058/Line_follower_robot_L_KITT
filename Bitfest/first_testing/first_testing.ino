 //motor_pins..................................
#define mright1  3
#define mright2  4
#define mrighten 10
#define mleft1   5
#define mleft2   6
#define mleften  11

int leftbasespeed = 180;
int rightbasespeed = 180; 

 //tcrt_parameters.............................
#define tcrtnum  6

int tcrtstandard[tcrtnum]={200, 150, 200, 275,225 , 150};
int tcrtvalue[tcrtnum]={1, 0, 0, 1, 0, 0};

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
  if(value == 100111 || value == 000111 || value == 011111 ){
    turnright90();
    }
  else if(value == 100101 || value == 000101){
    for(;;){
      if(analogRead(3)<tcrtstandard[3] && analogRead(5)>tcrtstandard[5]){
      break;
      }
      forward();
      }
    turnright135();
    }
  else if(value == 000110 || value == 000010 || value == 001010 || value == 010010 || value == 011010 ||value == 001001 || value == 010001 || value == 011001 || value == 011011){
    turnright30();
    }
  else if(value == 000011 || value == 000001 ){
    turnright45();
    }
  else if(value == 111111){
    pause();
    }
  else if(value == 100100 || value == 000100 || value == 100000 || value == 111100 || value == 101100 || value == 100110){
    forward();
    }
  else if(value == 011100){
    turnleft90();
    }
  else if(value == 110100 || value == 010100){
    for(;;){
      if(analogRead(3)<tcrtstandard[3] && analogRead(1)>tcrtstandard[1]){
      break;
      }
      forward();
      }
    turnleft135();
    }
  else if(value == 001100 || value == 001000){
    turnleft30();
    }
  else if(value == 011000 || value == 010000){
    turnleft45();
    }
  
}

void forward(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten,rightbasespeed);
  prevact= 1;
  }

void pause(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,HIGH);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,HIGH);
  prevact= 2;
  }

void turnright45(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften,leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  prevact= 3;
  }

void turnleft45(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  prevact= 4;
  }

void turnright60(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  prevact= 5;
  }

void turnleft60(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  prevact= 6;
  }

void turnright90(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, rightbasespeed);
  delay(500);
  prevact= 7;
  }

void turnleft90(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  delay(500);
  prevact= 8;
  }

void turnright120(){
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright2,HIGH);
  digitalWrite(mright1,LOW);
  analogWrite(mrighten, rightbasespeed);
  delay(750);
  prevact= 9;
  }

void turnleft120(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, rightbasespeed);
  delay(750);
  prevact= 10;
  }
  void rotate(){
  digitalWrite(mleft2,HIGH);
  digitalWrite(mleft1,LOW);
  analogWrite(mleften, leftbasespeed);
  digitalWrite(mright1,LOW);
  digitalWrite(mright2,HIGH);
  analogWrite(mrighten, rightbasespeed);
  delay(750);
  prevact= 11;
  }
