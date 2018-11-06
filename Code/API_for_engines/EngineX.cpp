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

void EngineX::stopEngineLX()            // ��������� ������ ������. �������� IN ���� �� ������
{
	analogWrite(ENA_L, 0);

	return;
}
void EngineX::stopEngineRX()           // ��������� ������� ������. �������� IN ���� �� ������
{
	analogWrite(ENB_R, 0);

	return;
}
void EngineX::stopEnginesX()          //��������� ����� �������
{
	stopEngineLX();
	stopEngineRX();

	return;
}

void EngineX::fullStopX()            //��������� �� ������� ����� � ��������� LOW
{
	stopEnginesX();
	EngineA::stopEngines();
}

void EngineX::goForwardLX(short power = 255, short timeM = 0)      // ����� ��������� � ������������ ��������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����
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

void EngineX::goForwardRX(short power = 255, short timeM = 0)      // ������ ���������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����
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

void EngineX::goBackLX(short power = 255, short timeM = 0)      // ����� ��������� � ������������ ��������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����
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

void EngineX::goBackRX(short power = 255, short timeM = 0)      // ������ ���������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����
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