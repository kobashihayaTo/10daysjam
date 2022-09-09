#pragma once
#include "DxLib.h"
#include "math.h"
#include "vector"

#include "PlayerBullet.h"
class Player
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
	void Update(char*keys,char*oldkeys);

	///<summary>
	///�`��
	///</summary>
	void Draw();

	///<summary>
	///�W�����v
	///</summary>
	void Jamp(char* keys, char* oldkeys);

	///<summary>
	///���
	///</summary>
	void Dodge(char* keys, char* oldkeys);
	/// <summary>
	/// �U��
	/// </summary>
	void Attack(char* keys, char* oldkeys);

public:
	int Gettrans_X();

	int Gettrans_Y();



	//void SetBullet() {
	//	bullet_->Update();
	//}

	VECTOR X;

	

private:

	VECTOR translation;

	PlayerBullet* bullet_;
	//�v���C���[
	float radius = 16.0f;
	float move = 5;
	float GetPlayertrans_ = 100.0f;
	//--------------------
	//�W�����v---------------------
	bool jflag = false;
	float y_temp = 0;
	float y_prev = 0;
	int jampChange = 25;


	bool dflag = false;
	//----------------------------
	//�e---------------------------
	bool aflag = false;
	float Bulletmove_X = 0;
	float Bulletmove_Y = 0;
	
	static const int BulletNum = 50;

	int shot_Right_X[BulletNum];
	int shot_Right_Y[BulletNum];
	int shot_Left_X[BulletNum];
	int shot_Left_Y[BulletNum];


	int isShot_Right[BulletNum];
	int isShot_Left[BulletNum];

	int bulletCooltime = 0;
	//---------------------------
	bool Rflag = true;
	bool Lflag = false;

	int memory_left_Y;

	int HP_X = 200;
	int HP_Y = 48;

	int HP_;
	int BUF[3];
	int DEBUF[3];

};

