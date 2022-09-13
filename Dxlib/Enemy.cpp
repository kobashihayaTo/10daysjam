#include "Enemy.h"
#include "Player.h"

void Enemy::Initialize()
{
	//���W
	//�p�����[�^�[
	translation.x = 0;
	translation.y = 0;
	translation.z = 0;
	//�����t���O
	aliveFlag = 0;
	//�ړ��t���O
	moveFlag = 0;
	//���X�|���^�C�}�[
	responTimer = 50.0f;
	//�ړ��^�C�}�[
	moveTimer = 100.0f;

	//�̗�
	HP = 200;

	radius = 32;
	//�d��
	yAdd = 0.0f;

}

void Enemy::Update(float x, float y, int Height, int Width)
{
	if (aliveFlag != 1)
	{
		Respon(x, y, Height, Width);
	}
	else if (aliveFlag == 1)
	{
		switch (moveFlag)
		{
		case 0:
			Move(x, y);
			if (translation.x <= 900 && moveFlag != 1)
			{
				moveFlag = 1;
			}
			break;
		case 1:
			if (moveTimer != 0)
			{
				moveTimer -= 0.5f;
			}
			if (moveTimer <= 0.0f)
			{
				moveTimer = 100.0f;
				moveFlag = 2;
			}
			break;
		case 2: //�U��
			Attack(x, y);
			if (moveTimer != 0)
			{
				moveTimer -= 0.5f;
			}
			if (moveTimer <= 0.0f)
			{
				moveTimer = 20.0f;
				moveFlag = 3;
			}
			break;
		case 3: //���
			Leave(x, y);
			if (moveTimer != 0)
			{
				moveTimer -= 0.5f;
			}
			if (moveTimer <= 0.0f)
			{
				moveTimer = 200.0f;
				moveFlag = 2;
			}
			break;
		}

	}
	DrawFormatString(0, 15, GetColor(255, 255, 255), "�t���O:%d", moveFlag);
}

void Enemy::Draw()
{
	int color = GetColor(255, 255, 0);

	if (aliveFlag == 1)
	{
		DrawCircle(translation.x, translation.y, radius, color, TRUE);
	}

	DrawFormatString(600, 0, color, "���W[%d]", aliveFlag);


	DrawFormatString(0, 30, color, "�^�C�}�[[%f]", responTimer);
}

void Enemy::Respon(float X, float Y, int Height, int Width)
{
	if (responTimer != 0.0f && aliveFlag != 1)
	{
		responTimer -= 0.5f;
	}
	if (responTimer <= 0.0f && aliveFlag != 1)
	{
		responTimer = 50.0f;
		translation.x = Width;
		translation.y = 690;
		aliveFlag = 1;	//�����t���O�ω�
	}
}

void Enemy::Move(float x, float y)
{
	translation.x -= 1.5f;
}

void Enemy::Attack(float x, float y)
{
	if (x < translation.x - radius)
	{
		translation.x += -2.0f;
	}
	else if (x > translation.x + radius)
	{
		translation.x += 2.0f;
	}
}

void Enemy::Leave(float x, float y)
{
	if (x < translation.x - radius)
	{
		translation.x += 2.8f;
	}
	else if (x > translation.x + radius)
	{
		translation.x += -2.8f;
	}
}