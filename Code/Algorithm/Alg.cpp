#include "Ir.h"
#include<Servo.h>
#include"EngineA.h"

EngineA en = EngineA(7,6,5,4);
Ir ir = Ir();
Servo s = Servo();

void Stop()
{
  s.write(90);
  en.EngineA::goBack();
  while(1)
{
  Results r = ir.getAll();
  if(r.middle > 27 && r.left >= 11 && r.right >= 11) break;
  delay(100);
}
  en.stopEngines();  
}
void Go()
{
   s.write(90);
   en.EngineA::goForward();
}
void ttR()    //правее
{
  s.write(75);
  delay(700);
  s.write(90);
}
void ttL()    //левее
{
  s.write(105);
  delay(700);
  s.write(90);
}
void Right()
{
  s.write(60);
}
void Left()
{
  s.write(125);
}

void makeDecision()
{
  Results r = ir.getAll();

  if(r.left == 9 && r.middle == 19 && r.right == 9)
  {
    Stop();
  }
  if(r.left > 10 && r.middle >= 30 && r.right > 10)
  {
    Go();
  }
  if(r.left <= 10 && r.middle >= 30 && r.right > 12)
  {
    ttR();
  }
  if(r.left > 12 && r.middle >= 30 && r.right <= 10)
  {
    ttL();
  }
  if(r.middle < 30)
  {
    if(r.left > 14)
    {
      Left();
    }
    if(r.right > 14)
    {
      Right();
    }
    else
      Stop();
  }
}
void setup()
{
 s.attach(10);
 s.write(90);
}

void loop()
{
  makeDecision();
}
