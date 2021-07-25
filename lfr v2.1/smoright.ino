float err, preverr=err;
int value1, n=1;
  
float smooth(){
  value =tcrtvalue[4]*3+tcrtvalue[5]*2+tcrtvalue[6];
  value=value/(tcrtvalue[4]+tcrtvalue[5]+tcrtvalue[6]);
  
  err = value - stdvalue ;
  p=err*kp;
  d=kd*(err - preverr);
  m = p+d;
  if(err!=preverr){
  preverr=err;}
  return m;  
  }
