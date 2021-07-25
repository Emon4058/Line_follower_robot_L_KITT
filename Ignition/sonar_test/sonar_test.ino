#define tr1 2
#define ec1 7
#define tr2 10
#define ec2 11
long ti1;
int d1;
long ti2;
int d2;

void setup() {
  pinMode(tr1, OUTPUT);
  pinMode(ec1, INPUT);
  pinMode(tr2, OUTPUT);
  pinMode(ec2, INPUT);
  Serial.begin(2000000);
}

void loop() {
 digitalWrite(tr1, LOW);
 delayMicroseconds(2);
 digitalWrite(tr1, HIGH);
 delayMicroseconds(10);
 digitalWrite(tr1, LOW);
 ti1=pulseIn(ec1,HIGH);
 d1=ti1*(0.034/2);


 digitalWrite(tr2, LOW);
 delayMicroseconds(2);
 digitalWrite(tr2, HIGH);
 delayMicroseconds(10);
 digitalWrite(tr2, LOW);
 ti2=pulseIn(ec2,HIGH);
 d2=ti2*(0.034/2);
 Serial.println(d2);
 }
