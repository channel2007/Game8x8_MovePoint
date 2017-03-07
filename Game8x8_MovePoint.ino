/*****************************************************************************
* Game8x8-�����I���յ{��.
*
* created  by channel
*
* todo list:
*
* note:
*
****************************************************************************/
#include "Game8x8Tone.h"
#include "Game8x8JoyStick.h"
#include "Game8x8Time.h"
#include "Game8x8Graphics.h"

// ø�Ϩ��.
Game8x8Graphics game8x8Graphics = Game8x8Graphics();
// �n����.
Game8x8JoyStick game8x8JoyStick = Game8x8JoyStick();
// ���ﾹ���.
Game8x8Tone		game8x8Tone = Game8x8Tone();

// ø�ϧ�s�ɯ�.
Game8x8Time TimeGraphicsUpdate = Game8x8Time();
// �n���s�ɯ�.
Game8x8Time TimeMoveX = Game8x8Time();
Game8x8Time TimeMoveY = Game8x8Time();

// ��l��m.
int x = 4;
int y = 4;

//---------------------------------------------------------------------------
// ��l.
//---------------------------------------------------------------------------
void setup()
{
	Serial.begin(9600);

	// �M���e��.
	game8x8Graphics.clearDisplay(0);
	// ��s.
	game8x8Graphics.setPixcls(x, y, 1);
	game8x8Graphics.update();
}

//---------------------------------------------------------------------------
// �D�j��.
//---------------------------------------------------------------------------
void loop() {
	// *���ʷn��X.
	int mx = game8x8JoyStick.getJoyX();
	if (mx != 5) {
		// �k��.
		if (mx < 5) {
			if (mx < 1) { mx = 1; }
			if (TimeMoveX.update(mx * 40)) {
				x++;
				if (x > 7) { x = 7; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// �o�X�n��.
			game8x8Tone.playTone(262, 33);
		}
		// ����.
		else
		{
			if (mx > 9) { mx = 10; }
			int mxT = (5 - (mx - 5));
			if (mxT == 0) { mxT = 1; }
			if (TimeMoveX.update(mxT * 40)) {
				x--;
				if (x < 1) { x = 0; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// �o�X�n��.
			game8x8Tone.playTone(294, 33);
		}
	}

	// *���ʷn��Y.
	int my = game8x8JoyStick.getJoyY();
	if (my != 5) {
		// �k��.
		if (my < 5) {
			if (my < 1) { my = 1; }
			if (TimeMoveY.update(my * 40)) {
				y++;
				if (y > 7) { y = 7; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// �o�X�n��.
			game8x8Tone.playTone(330, 33);
		}
		// ����.
		else
		{
			if (my > 9) { my = 10; }
			int myT = (5 - (my - 5));
			if (myT == 0) { myT = 1; }
			if (TimeMoveY.update(myT * 40)) {
				y--;
				if (y < 1) { y = 0; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// �o�X�n��.
			game8x8Tone.playTone(349, 33);
		}

	}

	// ø�ϧ�s�ɯ�-FPS 30.
	if (TimeGraphicsUpdate.update(33)) {
		// ��s.
		game8x8Graphics.update();
	}
}
