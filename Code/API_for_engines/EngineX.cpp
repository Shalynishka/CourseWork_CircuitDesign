#include"EngineX.h"

EngineX::EngineX(short in1, short in2, short in3, short in4, short ena, short enb) : EngineA::EngineA(in1, in2, in3, in4)
{
	ENA_L = ena;
	ENB_R = enb;
	pinMode(ENA_L, OUTPUT);
	pinMode(ENB_R, OUTPUT);
	analogWrite(ENA_L, 0);
	analogWrite(ENB_R, 0);
}

void EngineX::stopEngineLX()            // остановка левого мотора. Значения IN роли не играют
{
	analogWrite(ENA_L, 0);

	return;
}
void EngineX::stopEngineRX()           // остановка правого мотора. Значения IN роли не играют
{
	analogWrite(ENB_R, 0);

	return;
}
void EngineX::stopEnginesX()          //остановка обоих моторов
{
	stopEngineLX();
	stopEngineRX();

	return;
}

void EngineX::fullStopX()            //остановка со сбросом пинов в состояние LOW
{
	stopEnginesX();
	EngineA::stopEngines();
}

void EngineX::goForwardLX(short power = 255, short timeM = 0)      // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
{
	goForwardL();
	analogWrite(ENA_L, power);
	if (timeM)
	{
		delay(power);
		stopEngineLX();
	}

	return;
}

void EngineX::goForwardRX(short power = 255, short timeM = 0)      // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
{
	goForwardR();
	analogWrite(ENB_R, power);
	if (timeM)
	{
		delay(power);
		stopEngineRX();
	}

	return;
}

void EngineX::goForwardX(short power = 255, short timeM = 0)
{
	goForward();
	analogWrite(ENB_R, power);
	analogWrite(ENA_L, power);
	if (timeM)
	{
		delay(timeM);
		stopEnginesX();
	}
}

void EngineX::goBackLX(short power = 255, short timeM = 0)      // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
{
	goBackL();
	analogWrite(ENA_L, power);
	if (timeM)
	{
		delay(power);
		stopEngineLX();
	}

	return;
}

void EngineX::goBackRX(short power = 255, short timeM = 0)      // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ
{
	goBackR();
	analogWrite(ENB_R, power);
	if (timeM)
	{
		delay(power);
		stopEngineRX();
	}

	return;
}

void EngineX::goBackX(short power = 255, short timeM = 0)
{
	goBack();
	analogWrite(ENB_R, power);
	analogWrite(ENA_L, power);
	if (timeM)
	{
		delay(timeM);
		stopEnginesX();
	}
}