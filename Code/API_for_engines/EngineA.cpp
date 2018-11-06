#include"EngineA.h"
//3, 5, 6, 9, 10, и 11. - шим дл€ Nano
//EngineA - класс, дл€ использовани€ без шима. ENA и ENB коротить на 5v р€дом с ними.
EngineA::EngineA(short in1, short in2, short in3, short in4)
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

void EngineA::stopEngineL()          //остановить левый двигатель 
{
	digitalWrite(IN2, LOW);
	digitalWrite(IN1, LOW);

	return;
}
void EngineA::stopEngineR()          //остановить правый двигатель
{
	digitalWrite(IN4, LOW);
	digitalWrite(IN3, LOW);
}
void EngineA::stopEngines()          //остановить оба
{
	stopEngineL();
	stopEngineR();
}
//первое направление вращени€ двигателей
void EngineA::goForwardL(short timeM = 0)    //запуск левого двигател€ в одну сторону.
{                                   //ѕараметр timeM определ€ет задержку, после которой двигатель выключитс€. ≈сли задержки нет, двигатель не отключитс€
	if (timeM)
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
void EngineA::goForwardR(short timeM = 0)    //јналогично дл€ правого вдвигател€
{
	if (timeM)
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
void EngineA::goForward(short timeM = 0)  //запуск двух двигателей с возможностью задержки. 
{
	if (timeM)
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

//второе направление вращени€ двигателей
void EngineA::goBackL(short timeM = 0)    //запуск левого двигател€ в другую сторону.
{                                   //ѕараметр timeM определ€ет задержку, после которой двигатель выключитс€. ≈сли задержки нет, двигатель не отключитс€
	if (timeM)
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
void EngineA::goBackR(short timeM = 0)    //јналогично дл€ правого вдвигател€
{
	if (timeM)
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
void EngineA::goBack(short timeM = 0)  //запуск двух двигателей с возможностью задержки. 
{
	if (timeM)
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

//EngineX - наследник класса EngineA, сочетает в себе работу с шимом, т.е., возможность задавать мощность двигател€. ¬опрос по поводу значени€ по умолчанию!!!!

