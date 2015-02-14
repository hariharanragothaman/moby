int   pass[4]={
  1,2,3,4};
int Q[4]={
  3,7,5,9};
int key;
void setup()
{
  Serial.begin(9600);
  for(int i=0;i<4;i++)
    pinMode(Q[i],INPUT);
  attachInterrupt(0,dtmf,RISING);
}
int dtmf()
{
  key=0;
  for(int i=0;i<4;i++)
    key+=digitalRead(Q[i])<<i;
  Serial.println(key);
  return;
}
int g[4];
void loop()
{
  if(key)
  {
    if(key==11)
    {
      for(int i=0;i<4;i++)
        g[i]=attachInterrupt(0,dtmf,RISING);
      for(int i=0;i<4;i++)
        check(i);
    }
  }
}
boolean check(int d)
{
  for(int c=0;c<4;c++)
  {
    if(g[d]==pass[d])
    { 
      return 1;
    }
    else 
      return 0;
  }
}





