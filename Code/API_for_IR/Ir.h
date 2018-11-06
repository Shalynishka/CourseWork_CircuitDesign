#ifndef Ir_h
#define Ir_h

#include<Arduino.h>

struct Results
{
  unsigned int left;
  unsigned int middle;
  unsigned int right;
};


//#define CRITICAL    Results(9,19,9)

//#define LAST_SAFE Results(27,24,27)
class Ir
{
  int pinL, pinR, pinM;
  unsigned int lastTime = 0;
public:
  //default constructor
  Ir();
  //special constructor
  Ir(byte pl, byte pm, byte pr);
  //Left
  //---------------------------------
  unsigned int getDistanceLeft(bool avoidBurstRead = true);//левый и правйы - GP2Y0A21YK0F

  //Right
  //-----------------------------------
  unsigned int getDistanceRight(bool avoidBurstRead = true); //левый и правйы - GP2Y0A21YK0F
  //Middle
  //----------------------------------
  unsigned int getDistanceMid(bool avoidBurstRead = true); // средний - GP2Y0A02YK0F

  Results getAll(); // все данные структурой
};
#endif
