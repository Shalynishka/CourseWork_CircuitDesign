class Serv
{
  short pin;

  public:
  Serv(int p)
  {
    pin = p;
    pinMode(p, OUTPUT);
  }
  // 0 градусов. По идее, налево, 544
  void goLeft()
  {
    digitalWrite(servo, HIGH);
    delayMicroseconds(544);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000-544);
    delay(1);
  }
  //180- направо, 2400
  void goRight();
  {
    digitalWrite(servo, HIGH);
    delayMicroseconds(2400);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000-2400);
    delay(1);
  }
  //выравнять
  void goMiddle(), 1520
  {
    digitalWrite(servo, HIGH);
    delayMicroseconds(1520);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000-1520);
    delay(1);
  }
  //задать угол
  void goSome(int d)
  {
    digitalWrite(servo, HIGH);
    delayMicroseconds(d);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000-d);
    delay(1);
  }
}
/*void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}*/
