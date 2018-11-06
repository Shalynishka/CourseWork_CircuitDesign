#include"EngineA.h"
//3, 5, 6, 9, 10, � 11. - ��� ��� Nano
//EngineA - �����, ��� ������������� ��� ����. ENA � ENB �������� �� 5v ����� � ����.
EngineA::EngineA(short in1, short in2, short in3, short in4)
{
	IN1 = in1;
	IN2 = in2;
	IN3 = in3;
	IN4 = in4;
	pinMode(IN1, OUTPUT);  //�����
	pinMode(IN2, OUTPUT);  //���������
	pinMode(IN3, OUTPUT);       //������
	pinMode(IN4, OUTPUT);       //���������
}

void EngineA::stopEngineL()          //���������� ����� ��������� 
{
	digitalWrite(IN2, LOW);
	digitalWrite(IN1, LOW);

	return;
}
void EngineA::stopEngineR()          //���������� ������ ���������
{
	digitalWrite(IN4, LOW);
	digitalWrite(IN3, LOW);
}
void EngineA::stopEngines()          //���������� ���
{
	stopEngineL();
	stopEngineR();
}
//������ ����������� �������� ����������
void EngineA::goForwardL(short timeM = 0)    //������ ������ ��������� � ���� �������.
{                                   //�������� timeM ���������� ��������, ����� ������� ��������� ����������. ���� �������� ���, ��������� �� ����������
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
void EngineA::goForwardR(short timeM = 0)    //���������� ��� ������� ����������
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
void EngineA::goForward(short timeM = 0)  //������ ���� ���������� � ������������ ��������. 
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

//������ ����������� �������� ����������
void EngineA::goBackL(short timeM = 0)    //������ ������ ��������� � ������ �������.
{                                   //�������� timeM ���������� ��������, ����� ������� ��������� ����������. ���� �������� ���, ��������� �� ����������
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
void EngineA::goBackR(short timeM = 0)    //���������� ��� ������� ����������
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
void EngineA::goBack(short timeM = 0)  //������ ���� ���������� � ������������ ��������. 
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

//EngineX - ��������� ������ EngineA, �������� � ���� ������ � �����, �.�., ����������� �������� �������� ���������. ������ �� ������ �������� �� ���������!!!!

