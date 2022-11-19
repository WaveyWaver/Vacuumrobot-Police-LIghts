int Led1 = 5;
int Led2 = 6;
int Sens = 8;
int Read = 0;
void setup() 
{
 pinMode(Led1, OUTPUT);
 pinMode(Led2, OUTPUT);
 pinMode(Sens, INPUT);
}
void loop() 
{
  Read = digitalRead(Sens);
  if (Read == 1)
  {
    digitalWrite(13, HIGH);
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  if (Read == 0)
  {
    for(int i=0; i<5; i++) // Classic LR
      {
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      delay(300);
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, HIGH);
      delay(300);
      }
    for(int i=0; i<10; i++) //Sweeper Style Strobe
    {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
        for(int i=0; i<4; i++)
        {
        digitalWrite(Led1, HIGH);
        delay(50);
        digitalWrite(Led1, LOW);
        delay(20);
       }
       for(int i=0; i<4; i++)
    {
      digitalWrite(Led2, HIGH);
      delay(50);
      digitalWrite(Led2, LOW);
      delay(20);
    }
 }
    
    
  }
  else
  {
    for(int i=0; i<2; i++) //double strobe
       {
        digitalWrite(13, HIGH);
        delay(50);
        digitalWrite(13, LOW);
        delay(100);
        digitalWrite(13, HIGH);
        delay(50);
        digitalWrite(13, LOW);
        delay(200);
      }
  }
}
void doubleStrobe(int i)
{
  for(i; i<10; i++) //double strobe
       {
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        delay(50);
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        delay(100);
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        delay(50);
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        delay(200);
      }
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      delay(50);
}
