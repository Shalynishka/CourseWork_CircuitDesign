#ifndef EngineA_h
#define EngineA_h
#include<Arduino.h>
class EngineA
{
	short IN1, IN2, IN3, IN4; // Пины на драйвере L298N
public:
	EngineA(short in1, short in2, short in3, short in4);

	void stopEngineL();         //остановить левый двигатель 
	void stopEngineR();          //остановить правый двигатель

	void stopEngines();          //остановить оба

	//первое направление вращения двигателей
	void goForwardL(short timeM = 0);   //запуск левого двигателя в одну сторону.
										//Параметр timeM определяет задержку, после которой двигатель выключится. Если задержки нет, двигатель не отключится
		
	void goForwardR(short timeM = 0);   //Аналогично для правого вдвигателя
	
	void goForward(short timeM = 0);  //запуск двух двигателей с возможностью задержки. 
	

	//второе направление вращения двигателей
	void goBackL(short timeM = 0);    //запуск левого двигателя в другую сторону.
	                                  //Параметр timeM определяет задержку, после которой двигатель выключится. Если задержки нет, двигатель не отключится
		
	void goBackR(short timeM = 0);    //Аналогично для правого вдвигателя
	
	void goBack(short timeM = 0);  //запуск двух двигателей с возможностью задержки. 
	
};
#endif