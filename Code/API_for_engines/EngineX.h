#ifndef EngineX_h
#define EngineX_h

#include"EngineA.h"
class EngineX : public EngineA
{
	short ENA_L, ENB_R;
public:
	EngineX(short in1, short in2, short in3, short in4, short ena, short enb) : EngineA(in1, in2, in3, in4);

	void stopEngineLX();            // остановка левого мотора. Значения IN роли не играют
	void stopEngineRX();           // остановка правого мотора. Значения IN роли не играют

	void stopEnginesX();         //остановка обоих моторов

	void fullStopX();           //остановка со сбросом пинов в состояние LOW


	void goForwardLX(short power = 255, short timeM = 0);      // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ


	void goForwardRX(short power = 255, short timeM = 0);      // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ


	void goForwardX(short power = 255, short timeM = 0);

	void goBackLX(short power = 255, short timeM = 0);     // Левый двигатель с регулировкой мощности. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ

	void goBackRX(short power = 255, short timeM = 0);     // Правый двигатель. по умолчанию максимальная мощность. Но какое ей соответствует значение? АЛЯРМ

	void goBackX(short power = 255, short timeM = 0);

};
#endif