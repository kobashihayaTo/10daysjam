#include "Player.h"

void Player::Initialize()
{
	translation.x = 100;
	translation.y = 660;
}

void Player::Update(char* keys, char* oldkeys)
{
	if (keys[KEY_INPUT_RIGHT]==1) 
	{
		translation.x += move;
	}
	if (keys[KEY_INPUT_LEFT] == 1)
	{
		translation.x -= move;
	}
	Dodge(keys, oldkeys);
	Jamp(keys, oldkeys);

}

void Player::Draw()
{

	DrawBox(translation.x+ radius, translation.y+ radius, translation.x - radius, translation.y - radius,GetColor(255, 255, 255), true);
	DrawFormatString(100, 0, GetColor(255, 255, 255), "ç¿ïW:%f",translation.z);
	if (dflag == true)
	{
		DrawBox(100, 100, 100,100, GetColor(255, 255, 255), true);
	}
}

void Player::Jamp(char* keys, char* oldkeys)
{

	if (jflag == true) {
		y_temp = translation.y;
 		translation.y += (translation.y - y_prev) + 1;
		y_prev = y_temp;
		//ÇÃÇøÇ…ïœçX----
		if (translation.y == 660) {
			jflag = false;
		}
		//--------------
	}
	if (keys[KEY_INPUT_UP] && jflag == false)
	{
		jflag = true;
		y_prev = translation.y;
		translation.y = translation.y - jampChange;
	}
}

void Player::Dodge(char* keys, char* oldkeys)
{
	if (keys[KEY_INPUT_M] == 1 && dflag == false)
	{
		dflag = true;
	}
	if (keys[KEY_INPUT_M] == 0&& dflag == true)
	{
		dflag = false;
		translation.z = 0;
		move = 5;
	}
	if (dflag == true&&translation.z<32)
	{
		translation.z += radius;
		move = 0;
	}
}

