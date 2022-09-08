#pragma once
#include "DxLib.h"
#include "math.h"
#include "vector"

#include "PlayerBullet.h"
class Player
{
public:
	///<summary>
	///初期化
	///</summary>
	///<param name="model">モデル</param>
	///<param name="textureHandle">テクスチャハンドル</param>
	void Initialize();

	///<summary>
	///更新
	///</summary>
	void Update(char*keys,char*oldkeys);

	///<summary>
	///描画
	///</summary>
	void Draw();

	///<summary>
	///ジャンプ
	///</summary>
	void Jamp(char* keys, char* oldkeys);

	///<summary>
	///回避
	///</summary>
	void Dodge(char* keys, char* oldkeys);
	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack(char* keys, char* oldkeys);

public:
	float Gettrans();

	//void SetBullet() {
	//	bullet_->Update();
	//}

	VECTOR X;

	VECTOR translation;

private:
	PlayerBullet* bullet_;

	float radius = 16.0f;
	float move = 5;
	float GetPlayertrans_ = 100.0f;

	bool jflag = false;
	float y_temp = 0;
	float y_prev = 0;
	int jampChange = 25;

	bool dflag = false;

	bool aflag = false;
	float Bulletmove = 0;
	float Bulletmove_Y = 0;

	static const int BulletNum = 50;
	int shot_Right[BulletNum];
	int shot_Left[BulletNum];
	int isShot_Right[BulletNum];
	int isShot_Left[BulletNum];
	int bulletCooltime = 0;

	bool Rflag = true;
	bool Lflag = false;

	
	int memory_left_Y;

	int X_;
	int Y_;
};

