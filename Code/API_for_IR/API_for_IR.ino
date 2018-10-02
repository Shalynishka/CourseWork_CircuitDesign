//Измерение дистанции. Так сказать, два варианта. Первый опирается на эксперименты других чуваков. Второй - от другого чувака, но предоставляется офф. сайтом ардуино.
class Ir
{
  const float k = 5/1024;
  float sl = 0;
  byte pin;
  unsigned int lastTime = 0; 
  public:
  Ir(byte p)
  {
    pin = p;
    pinMode(pin, INPUT);
  }

  unsigned int getDistance()
  {
    float volts = analogRead(pin)*k;                // считываем значение сенсора и переводим в напряжение
    float distance = 65*pow(volts, -1.10);          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk
    return distance;
  }
  unsigned int getDistance2(bool avoidBurstRead = true)
  {
    unsigned int distance ;

    if( !avoidBurstRead ) while( millis() <= lastTime + 20 ) {} //Ждем, пока датчик сделает пробу

    lastTime = millis();

    distance = 4800/(analogRead(pin)-20);

    if(distance > 80) return 81;
    else if(distance < 10) return 9;
        else return distance;
  }
};






void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
