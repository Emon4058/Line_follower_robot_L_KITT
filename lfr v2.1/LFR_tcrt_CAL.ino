
#define x 13
#define y 2
#define tcrtnum 6
int tcrtstandardh[tcrtnum]={0,0,0,0,0,0};
int tcrtstandardl[tcrtnum]={0,0,0,0,0,0};
int tcrtstandard[tcrtnum]={0,0,0,0,0,0};
void setup() {
  Serial.begin(9600);
    pinMode(x, INPUT);
    pinMode(y, INPUT);
}

void loop() {
   if(digitalRead(x)==1)
   {
      tcrtstandardh[0]=analogRead(A0);
      tcrtstandardh[1]=analogRead(A1);
      tcrtstandardh[2]=analogRead(A2);
      tcrtstandardh[3]=analogRead(A3);
      tcrtstandardh[4]=analogRead(A4);
      tcrtstandardh[5]=analogRead(A5);
   }
   if(digitalRead(y)==1)
   {
      tcrtstandardl[0]=analogRead(A0);
      tcrtstandardl[1]=analogRead(A1);
      tcrtstandardl[2]=analogRead(A2);
      tcrtstandardl[3]=analogRead(A3);
      tcrtstandardl[4]=analogRead(A4);
      tcrtstandardl[5]=analogRead(A5);
   }
   for(int i=0;i<tcrtnum;i++)
   {
      int tcrtstandard[i]={(tcrtstandardh[i]+tcrtstandardl[i])/2};
      Serial.print(tcrtstandard[i]);
      Serial.print(" ");
   }

}
