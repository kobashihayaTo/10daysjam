#include "System.h"

void System::Initialize()
{
	gameTimer = 0.0f;
	gameCount = 0;
}

void System::Update()
{
	gameTimer += 0.05f;
	if (gameTimer >= 20)
	{
		gameTimer = 0.0f;
		gameCount += 1;
	}
	DrawFormatString(0, 45, GetColor(255, 255, 255), "%f", gameTimer);
}
