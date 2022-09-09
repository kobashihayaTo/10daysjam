#include "System.h"

void System::Initialize()
{
	gameTimer = 0.0f;
	gameCount = 0;

	HP_ = LoadGraph("HPUI.png");
	LoadDivGraph("Buf.png", 3, 3, 1, 32, 32, BUF);
	LoadDivGraph("DBuf.png", 3, 3, 1, 32, 32, DEBUF);
}

void System::Update()
{
	gameTimer += 0.05f;
	if (gameTimer >= 1)
	{
		gameTimer = 0.0f;
		gameCount += 1;
		HP_X-=1.5;
	}
	if (gameCount >= 1)
	{
		if (HP_X >= 92.5) {
			//デバフ

		}
		else
		{
			//バフ

		}
	}

	DrawFormatString(0, 200, GetColor(255, 255, 255), "%f", gameTimer);
}

void System::Draw(int X_,int Y_)
{
	DrawBox(15, 15, HP_X, HP_Y, GetColor(0, 255, 0), true);//HPバー
	DrawGraph(0, 0, HP_, true);

	if (gameCount >= 1)
	{
		if (HP_X >= 92.5) {
			if (AnimetionTimer >= 0)
			{
				AnimetionTimer--;
			}
			if (AnimetionTimer <= 0)
			{
				AnimetionTimer = 8;
				AnimetionCount += 1;
				if (AnimetionCount > 2)
				{
					AnimetionCount = 0;
				}
			}
			//デバフ
			DrawGraph(X_ - 20, Y_ - 20, BUF[AnimetionCount], true);

		}
		else
		{
			if (AnimetionTimer >= 0)
			{
				AnimetionTimer--;
			}
			if (AnimetionTimer <= 0)
			{
				AnimetionTimer = 8;
				AnimetionCount += 1;
				if (AnimetionCount > 2)
				{
					AnimetionCount = 0;
				}
			}
			//デバフ
			DrawGraph(X_ - 20, Y_ - 20, DEBUF[AnimetionCount], true);
		}
	}
}
