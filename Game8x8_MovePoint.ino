/*****************************************************************************
* Game8x8-移動點測試程式.
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

// 繪圖函數.
Game8x8Graphics game8x8Graphics = Game8x8Graphics();
// 搖桿函數.
Game8x8JoyStick game8x8JoyStick = Game8x8JoyStick();
// 蜂鳴器函數.
Game8x8Tone		game8x8Tone = Game8x8Tone();

// 繪圖更新時脈.
Game8x8Time TimeGraphicsUpdate = Game8x8Time();
// 搖桿更新時脈.
Game8x8Time TimeMoveX = Game8x8Time();
Game8x8Time TimeMoveY = Game8x8Time();

// 初始位置.
int x = 4;
int y = 4;

//---------------------------------------------------------------------------
// 初始.
//---------------------------------------------------------------------------
void setup()
{
	Serial.begin(9600);

	// 清除畫面.
	game8x8Graphics.clearDisplay(0);
	// 更新.
	game8x8Graphics.setPixcls(x, y, 1);
	game8x8Graphics.update();
}

//---------------------------------------------------------------------------
// 主迴圈.
//---------------------------------------------------------------------------
void loop() {
	// *移動搖桿X.
	int mx = game8x8JoyStick.getJoyX();
	if (mx != 5) {
		// 右移.
		if (mx < 5) {
			if (mx < 1) { mx = 1; }
			if (TimeMoveX.update(mx * 40)) {
				x++;
				if (x > 7) { x = 7; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// 發出聲音.
			game8x8Tone.playTone(262, 33);
		}
		// 左移.
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
			// 發出聲音.
			game8x8Tone.playTone(294, 33);
		}
	}

	// *移動搖桿Y.
	int my = game8x8JoyStick.getJoyY();
	if (my != 5) {
		// 右移.
		if (my < 5) {
			if (my < 1) { my = 1; }
			if (TimeMoveY.update(my * 40)) {
				y++;
				if (y > 7) { y = 7; }
				game8x8Graphics.clearDisplay(0);
				game8x8Graphics.setPixcls(x, y, 1);
			}
			// 發出聲音.
			game8x8Tone.playTone(330, 33);
		}
		// 左移.
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
			// 發出聲音.
			game8x8Tone.playTone(349, 33);
		}

	}

	// 繪圖更新時脈-FPS 30.
	if (TimeGraphicsUpdate.update(33)) {
		// 更新.
		game8x8Graphics.update();
	}
}
