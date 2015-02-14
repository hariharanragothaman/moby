int d=0,i=0;
int decode()
{
  int r_val=0,DUR[12];
  if(pulseIn(15,LOW)>2000)
  {
    for(int i=0;i<12;i++)
    {
      DUR[i]=pulseIn(15,LOW);
    } 
    for(int i=0;i<12;i++)
    {
      if(DUR[i]>1000)
        r_val=r_val+(1<<i);
    }
  }
  return r_val;
}
void setup()
{
  pinMode(15,INPUT);
  Serial.begin(9600);
}
void loop()
{

  int v=decode();
  if(v)
  {
    Serial.println(v);
    delay(200);
  }
  switch(v)
  {
  case 244:
    i=i+30;
    i=(i<256)?255:i;
    break;
  case 245: 
    i=i-30;
    i=(i<=0)?255:i;
    break;
  case 229:
    d=!d;
    break;
  }
  if(d==0)
  {
    analogWrite(10,i);
    analogWrite(11,0);
  }
  else
  {
    analogWrite(11,i);
    analogWrite(10,0);

  }
}


