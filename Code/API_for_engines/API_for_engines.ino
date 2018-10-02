//3, 5, 6, 9, 10, и 11. - шим для Nano
//EngineA - класс, для использования без шима. ENA и ENB коротить на 5v рядом с ними.
class EngineA
{
    short IN1, IN2, IN3, IN4; // Пины на драйвере L298N
    public:
      EngineA(short in1, short in2, short in3, short in4)
      {
        IN1 = in1;
        IN2 = in2;
        IN3 = in3; 
        IN4 = in4;
        pinMode(IN1, OUTPUT);  //левый
        pinMode(IN2, OUTPUT);  //двигатель
        pinMode(IN3, OUTPUT);       //правый
        pinMode(IN4, OUTPUT);       //двигатель
      }

      void stopEngineL()          //остановить левый двигатель 
      {
        digitalWrite(IN2, LOW);
        digitalWrite(IN1, LOW);

        return;
      }
      void stopEngineR()          //остановить правый двигатель
      {
        digitalWrite(IN4, LOW);
        digitalWrite(IN3, LOW);
      }
      void stopEngines()          //остановить оба
      {
        stopEngineL();
        stopEngineR();
      }
      //первое направление вращения двигателей
      void goForwardL(short timeM = 0)    //запуск левого двигателя в одну сторону.
      {                                   //Параметр timeM определяет задержку, после которой двигатель выключится. Если задержки нет, двигатель не отключится
        if(timeM)
        {
          digitalWrite(IN2, HIGH);
          digitalWrite(IN1, LOW);
          delay(timeM);
          digitalWrite(IN2, LOW);          
        }
        else
        {
          digitalWrite(IN2, HIGH);
          digitalWrite(IN1, LOW);
        }
        return;
      }
      void goForwardR(short timeM = 0)    //Аналогично для правого вдвигателя
      {
       if(timeM)
        {
          digitalWrite(IN4, HIGH);
          digitalWrite(IN3, LOW);
          delay(timeM);
          digitalWrite(IN4, LOW);          
        }
        else
        {
          digitalWrite(IN4, HIGH);
          digitalWrite(IN3, LOW);
        }
        return;
      }
      void goForward(short timeM = 0)  //запуск двух двигателей с возможностью задержки. 
      {
        if(timeM)
        {
          goForwardL();
          goForwardR();
          delay(timeM);
          digitalWrite(IN2, LOW);
          digitalWrite(IN4, LOW);           
        }
        else
        {
          goForwardL();
          goForwardR();
        }
        return;
      }

      //второе направление вращения двигателей
      void goBackL(short timeM = 0)    //запуск левого двигателя в другую сторону.
      {                                   //Параметр timeM определяет задержку, после которой двигатель выключится. Если задержки нет, двигатель не отключится
        if(timeM)
        {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          delay(timeM);
          digitalWrite(IN1, LOW);          
        }
        else
        {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
        }
        return;
      }
      void goBackR(short timeM = 0)    //Аналогично для правого вдвигателя
      {
       if(timeM)
        {
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          delay(timeM);
          digitalWrite(IN3, LOW);          
        }
        else
        {
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
        }
        return;
      }
      void goBack(short timeM = 0)  //запуск двух двигателей с возможностью задержки. 
      {
        if(timeM)
        {
          goBackL();
          goBackR();
          delay(timeM);
          digitalWrite(IN1, LOW);
          digitalWrite(IN3, LOW);           
        }
        else
        {
          goBackL();
          goBackR();
        }
        return;
      }      
};

//EngineX - наследник класса EngineA, сочетает в себе работу с шимом, т.е., возможность задавать мощность двигателя. Вопрос по поводу значения по умолчанию!!!!
class EngineX: public EngineA
{
  short ENA_L, ENB_R;
  public:
  EngineX(short in1, short in2, short in3, short in4, short ena, short enb): EngineA(in1, in2, in3, in4) 
  {
    ENA_L = ena;
    ENB_R = enb;
    pinMode(ENA_L, OUTPUT);
    pinMode(ENB_R, OUTPUT);
    analogWrite(ENA_L, 0);
    analogWrite(ENB_R, 0);
  }
  void stopEngineLX()            // остановка левого мотора. Значения IN роли не играют
  {
    analogWrite(ENA_L, 0);

    return;
  }
  void stopEngineRX()           // остановка правого мотора. Значения IN роли не играют
  {
    analogWrite(ENB_R, 0);          

    return;
  }
  void stopEnginesX()          //остановка обоих моторов
  {
    stopEngineLX();
    stopEngineRX();

    return;
  }
  void fullStopX()            //остановка со сбросом пинов в состояние LOW
  {
    stopEnginesX();
    stopEngines();
  }
  
  void goForwardLX(short power = 255, short timeM = 0)      // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
  {
    goForwardL();
    analogWrite(ENA_L, power);
    if(timeM)
    {   
      delay(power);
      stopEngineLX();
    }

    return;
  }
  
  void goForwardRX(short power = 255, short timeM = 0)      // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
  {
    goForwardR();
    analogWrite(ENB_R, power);
    if(timeM)
    {    
      delay(power);
      stopEngineRX();
    }

    return;
  }

  void goForwardX(short power = 255, short timeM = 0)
  {
    goForward();
    analogWrite(ENB_R, power);
    analogWrite(ENA_L, power);
    if(timeM)
    {
      delay(timeM);
      stopEnginesX();
    }
  }

  void goBackLX(short power = 255, short timeM = 0)      // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
  {
    goBackL();
    analogWrite(ENA_L, power);
    if(timeM)
    {   
      delay(power);
      stopEngineLX();
    }

    return;
  }
  
  void goBackRX(short power = 255, short timeM = 0)      // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
  {
    goBackR();
    analogWrite(ENB_R, power);
    if(timeM)
    {    
      delay(power);
      stopEngineRX();
    }

    return;
  }

  void goBackX(short power = 255, short timeM = 0)
  {
    goBack();
    analogWrite(ENB_R, power);
    analogWrite(ENA_L, power);
    if(timeM)
    {
      delay(timeM);
      stopEnginesX();
    }
  }
};


//EngineX en = EngineX(1,2,3,4,5,6);


void setup() {
  // put your setup code here, to run once:
 // EngineA en = EngineA(1,2,3,4);
 // en.stopEngines();
 }

void loop() {
  // put your main code here, to run repeatedly:
  //en.stopEnginesX();
}
