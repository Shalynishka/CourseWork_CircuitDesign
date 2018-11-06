#include "Ir.h"


Ir::Ir()
{
  pinL = A0;
  pinMode(pinL, INPUT);
  pinR = A2;
  pinMode(pinR, INPUT);
  pinM = A1;
  pinMode(pinM, INPUT);
}

Ir::Ir(byte pl, byte pm, byte pr)
{
  pinL = pl;
  pinMode(pinL, INPUT);
  pinR = pr;
  pinMode(pinR, INPUT);
  pinM = pm;
  pinMode(pinM, INPUT);
}
  //Left
  //---------------------------------
unsigned int Ir::getDistanceLeft(bool avoidBurstRead = true) //левый и правйы - GP2Y0A21YK0F
  {
    unsigned int distance;

    if (!avoidBurstRead) while (millis() <= lastTime + 20) {} //Ждем, пока датчик сделает пробу

    lastTime = millis();

    distance = 4800 / (analogRead(pinL) - 20);

    if (distance > 53) return 57; //для левого 57
    else if (distance < 10) return 9;
    else return distance;
  }
  //Right
  //-----------------------------------
unsigned int Ir::getDistanceRight(bool avoidBurstRead = true) //левый и правйы - GP2Y0A21YK0F
{
  unsigned int distance;

  if (!avoidBurstRead) while (millis() <= lastTime + 20) {} //Ждем, пока датчик сделает пробу

  lastTime = millis();

  distance = 4800 / (analogRead(pinR) - 20);

  if (distance > 53) return 53;
  else if (distance < 10) return 9;
  else return distance;
}
  //Middle
  //----------------------------------
unsigned int Ir::getDistanceMid(bool avoidBurstRead = true) // средний - GP2Y0A02YK0F
{
  unsigned int distance;

  if (!avoidBurstRead) while (millis() <= lastTime + 20) {} //Ждем, пока датчик сделает пробу

  lastTime = millis();

  distance = 9462 / (analogRead(pinM) - 16.92);

  if (distance > 150) return 132;      //132 - четкое фиксирование
  else if (distance < 20) return 19;   //до 10 см. Потом ситуация, что препядствие далеко
  else return distance;
}

Results Ir::getAll()
{
  Results res = Results();
  res.left = Ir::getDistanceLeft();
  res.middle = Ir::getDistanceMid();
  res.right = Ir::getDistanceRight();
  return res;
}
