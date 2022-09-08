#pragma once
#include "DxLib.h"
#include "math.h"
class PlayerBullet
{
public:
	///<summary>
	///������
	///</summary>
	///<param name="model">���f��</param>
	///<param name="textureHandle">�e�N�X�`���n���h��</param>
	void Initialize();

	///<summary>
	///�X�V
	///</summary>
	void Update();

	///<summary>
	///�`��
	///</summary>
	void Draw();

private:
	bool aflag = false;
	float Bulletmove = 0;

	static const int BulletNum = 50;
	int shot_x[BulletNum];
	int isShot[BulletNum] = { 0 };
};

