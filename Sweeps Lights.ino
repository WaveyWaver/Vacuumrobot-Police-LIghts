//Configuration of Pins

int Led1 = 5;   //led pin 1
int Led2 = 6;   //led pin 2
int Sens = 8;   //charge detection

//Setup for Random modes
int Mode = 0;   
int Count = 0;

//Initializing Pins
void setup() 
{
 pinMode(Led1, OUTPUT);
 pinMode(Led2, OUTPUT);
 pinMode(Sens, INPUT);
}

//Main Code
void loop() 
{
  //Test if Battery is being Charged
  if (digitalRead(Sens) == 1)
  {
    //Turn of LEDs 1 and 2
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    //Flashing Onboard LED
    for(int i=0; i<2; i++)
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
  else
  {
    //Generate Random Numbers
    Mode = random(1,6);
    Count = random(5,20);
    
    //Starting the Lightshow
    switch (Mode)
    {
      case 1:
      classicRL(Count, 300);
      break;
      
      case 2:
      classicRL(Count, 200);
      break;

      case 3:
      multiStrobe(Count*2,2, 100);
      break;

      case 4:
      multiStrobe(Count,4, 50);
      break;

      case 5:
      sweeperStrobe(Count);
      break;

      case 6:
      inverseSweep(Count);
      break;
    }
  }
}
//Flashes the LED x times with x Speed with longer delay in between
void multiStrobe(int n, int flashes, int speed)
{
  for(int i= 0; i<n; i++) //double strobe
       {
        delay(speed);
        for(int i= 0; i< flashes; i++)
        {
          digitalWrite(Led1, HIGH);
          digitalWrite(Led2, HIGH);
          delay(speed/2);
          digitalWrite(Led1, LOW);
          digitalWrite(Led2, LOW);
          delay(speed);
        }
        delay(speed);
      }
}
//Multiple flashes on one side with short off times, no extra delay between LED 1 and 2
void sweeperStrobe(int n)
{
      for(int i=0; i<n; i++) //Sweeper Style Strobe
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
//Same as sweeperStrobe, but both LEDs are lit and the strobing one turns off
void inverseSweep(int n)
{
for(int i=0; i<n; i++) //Sweeper Style Strobe
  {
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  for(int i=0; i<4; i++)
    {
    digitalWrite(Led1, HIGH);
    delay(40);
    digitalWrite(Led1, LOW);
    delay(30);
    }
    digitalWrite(Led1, HIGH);
  for(int i=0; i<4; i++)
    {
    digitalWrite(Led2, HIGH);
    delay(40);
    digitalWrite(Led2, LOW);
    delay(30);
    }
    digitalWrite(Led2, HIGH);
  }
}
//Alternating between the two LEDs
void classicRL(int n, int speed)
{
  for(int i=0; i<n; i++) // Classic LR
      {
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      delay(speed);
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, HIGH);
      delay(speed);
      }
}
