#include "Player.h"

void Player::Initialize()
{
	translation.x = 100;
	translation.y = 660;
}

void Player::Update(char* keys, char* oldkeys)
{

	X = VGet(translation.x, translation.y, translation.z);

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key&PAD_INPUT_RIGHT|| keys[KEY_INPUT_RIGHT] == 1)
	{
		Rflag = true;
		Lflag = false;
		translation.x += move;

	}
	if (keys[KEY_INPUT_LEFT] == 1|| key & PAD_INPUT_LEFT)
	{
		Rflag = false;
		Lflag = true;
		translation.x -= move;
	}
	Dodge(keys, oldkeys);
	Jamp(keys, oldkeys);
	Attack(keys, oldkeys);
}

void Player::Draw()
{

	DrawBox((int)(translation.x+ radius), (int)(translation.y+ radius), (int)(translation.x - radius), (int)(translation.y - radius),GetColor(255, 255, 255), true);
	DrawFormatString(100, 0, GetColor(255, 255, 255), "ç¿ïW:%f", translation.x);
	DrawFormatString(100, 20, GetColor(255, 255, 255), "ç¿ïW:%f", Bulletmove_Y);
	if (dflag == true)
	{
		DrawCircle(100,100,10, GetColor(255, 255, 255), true);
	}

	if (Rflag == true) {

		for (int i = 0; i < BulletNum; i++) {
			if (isShot_Right[i] == 1) {
				DrawCircle((int)(Bulletmove + radius), Bulletmove_Y, 10, GetColor(255, 0, 0), true);
			}
		}
	}
	if (Lflag == true) {

		for (int i = 0; i < BulletNum; i++) {
			if (isShot_Left[i] == 1) {
				DrawCircle((int)(Bulletmove - radius), Bulletmove_Y, 10, GetColor(255, 0, 0), true);
			}
		}
	}
}

void Player::Jamp(char* keys, char* oldkeys)
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
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
	if (keys[KEY_INPUT_UP] && jflag == false|| key & PAD_INPUT_1 && jflag == false )
	{
		jflag = true;
		y_prev = translation.y;
		translation.y= translation.y - jampChange;
	}
}
//å„âÒÇµ
void Player::Dodge(char* keys, char* oldkeys)
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (keys[KEY_INPUT_C] == 1 && dflag == false || key & PAD_INPUT_4 && dflag == false)
	{
		dflag = true;
	}
	if (key & PAD_INPUT_4 && dflag == true)
	{
		dflag = false;
		translation.z = 0;
		move = 5;
	}
	if (dflag == true && translation.z < 32)
	{
		translation.z += radius;
		move = 0;
	}
}

void Player::Attack(char* keys, char* oldkeys)
{

	for (int i = 0; i < BulletNum; i++) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && bulletCooltime == 0 && Rflag == true)
		{
			aflag = true;
			if (aflag == true) {
				Bulletmove = translation.x;
				Bulletmove_Y = translation.y;
				if (isShot_Right[i] == 0)
				{
					shot_Right[i] = Bulletmove;
					isShot_Right[i] = 1;
					bulletCooltime = 9;
					break;
				}
			}
		}
		if (aflag == true) {
			if (isShot_Right[i] == 1) {
				Bulletmove += 5;
				break;
			}
		}
		if (Bulletmove>=1280)
		{
			aflag = false;
		}
 		if (shot_Right[i] <= 0)
		{
			isShot_Right[i] = 0;
		}
	}

	for (int i = 0; i < BulletNum; i++) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && bulletCooltime == 0 && Lflag == true)
		{

			if (isShot_Left[i] == 0)
			{
				shot_Left[i] = Bulletmove;
				isShot_Left[i] = 1;
				bulletCooltime = 9;
				break;
			}
		}
		if (isShot_Left[i] == 1) {
			Bulletmove -= 5;
		}
		if (shot_Left[i] <= 0)
		{
			isShot_Left[i] = 0;
		}
	}
	if (bulletCooltime > 0)
	{
		bulletCooltime--;
	}
}

float Player::Gettrans() { return translation.x, translation.y, translation.z; }