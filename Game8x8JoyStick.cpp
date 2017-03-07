/*****************************************************************************
*  8x8搖桿.
*
*  created  by channel
*
*  todo list:
*
*  note:
****************************************************************************/

#include "Game8x8JoyStick.h"

//---------------------------------------------------------------------------
// 建構式.
//---------------------------------------------------------------------------
Game8x8JoyStick::Game8x8JoyStick() {
	pinMode( 3, OUTPUT);
}

//---------------------------------------------------------------------------
// x.
// ->:5~0
// <-:5~10
//---------------------------------------------------------------------------
int Game8x8JoyStick::getJoyX() {
	value = analogRead(0);
	value /= 100;
	return value;
}

//---------------------------------------------------------------------------
// y.
// ^:5~0
// v:5~10
//---------------------------------------------------------------------------
int Game8x8JoyStick::getJoyY() {
	value = analogRead(1);
	value /= 100;
	return value;
}

//---------------------------------------------------------------------------
// z.
// 0:放開.
// 1:按下.
//---------------------------------------------------------------------------
int Game8x8JoyStick::getJoyZ() {
	value = digitalRead(7);

	//Serial.print(" | Z: ");
	//Serial.println(value, DEC);

	return value;
}
