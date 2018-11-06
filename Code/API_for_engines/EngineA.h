#ifndef EngineA_h
#define EngineA_h
#include<Arduino.h>
class EngineA
{
	short IN1, IN2, IN3, IN4; // ���� �� �������� L298N
public:
	EngineA(short in1, short in2, short in3, short in4);

	void stopEngineL();         //���������� ����� ��������� 
	void stopEngineR();          //���������� ������ ���������

	void stopEngines();          //���������� ���

	//������ ����������� �������� ����������
	void goForwardL(short timeM = 0);   //������ ������ ��������� � ���� �������.
										//�������� timeM ���������� ��������, ����� ������� ��������� ����������. ���� �������� ���, ��������� �� ����������
		
	void goForwardR(short timeM = 0);   //���������� ��� ������� ����������
	
	void goForward(short timeM = 0);  //������ ���� ���������� � ������������ ��������. 
	

	//������ ����������� �������� ����������
	void goBackL(short timeM = 0);    //������ ������ ��������� � ������ �������.
	                                  //�������� timeM ���������� ��������, ����� ������� ��������� ����������. ���� �������� ���, ��������� �� ����������
		
	void goBackR(short timeM = 0);    //���������� ��� ������� ����������
	
	void goBack(short timeM = 0);  //������ ���� ���������� � ������������ ��������. 
	
};
#endif