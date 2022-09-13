#pragma once
#include "DxLib.h"
#include <math.h>

class EnemyBullet
{
public:
	//�p�����[�^
	float translationX;
	float translationY;
	//���a
	float radius;
	//�����t���O
	int fireFlag;
	//���x
	float speed;
	//�U���^�C�}�[
	float attackTimer;
	//�d��
	float yAdd;

	void Initialize();
	void Update();
	void Fire(float x, float y);
	void Draw();

	void Oncollision(float playerX, float playerY, int playerRadius, int playerFlag, int hp);
};