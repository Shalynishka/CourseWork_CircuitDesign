#ifndef EngineX_h
#define EngineX_h

#include"EngineA.h"
class EngineX : public EngineA
{
	short ENA_L, ENB_R;
public:
	EngineX(short in1, short in2, short in3, short in4, short ena, short enb) : EngineA(in1, in2, in3, in4);

	void stopEngineLX();            // ��������� ������ ������. �������� IN ���� �� ������
	void stopEngineRX();           // ��������� ������� ������. �������� IN ���� �� ������

	void stopEnginesX();         //��������� ����� �������

	void fullStopX();           //��������� �� ������� ����� � ��������� LOW


	void goForwardLX(short power = 255, short timeM = 0);      // ����� ��������� � ������������ ��������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����


	void goForwardRX(short power = 255, short timeM = 0);      // ������ ���������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����


	void goForwardX(short power = 255, short timeM = 0);

	void goBackLX(short power = 255, short timeM = 0);     // ����� ��������� � ������������ ��������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����

	void goBackRX(short power = 255, short timeM = 0);     // ������ ���������. �� ��������� ������������ ��������. �� ����� �� ������������� ��������? �����

	void goBackX(short power = 255, short timeM = 0);

};
#endif