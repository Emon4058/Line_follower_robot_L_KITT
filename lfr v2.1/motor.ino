int m1, m2;



void motor(float m){
  m1=255-m;
  Serial.print(m1);
  Serial.print("  ");
  if(m1>255)m1=255;
  m2=255+m;
  Serial.print(m2);
  Serial.print("  ");
  if(m2>255)m2=255;
  digitalWrite(mleft1,HIGH);
  digitalWrite(mleft2,LOW);
  analogWrite(mleften, m1);
  digitalWrite(mright1,HIGH);
  digitalWrite(mright2,LOW);
  analogWrite(mrighten, m2);
  delayMicroseconds(1);
  
  
  }
