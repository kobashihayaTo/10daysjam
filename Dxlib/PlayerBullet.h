#pragma once
#include "DxLib.h"
#include "math.h"
class PlayerBullet
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
	void Update();

	///<summary>
	///描画
	///</summary>
	void Draw();

private:
	bool aflag = false;
	float Bulletmove = 0;

	static const int BulletNum = 50;
	int shot_x[BulletNum];
	int isShot[BulletNum] = { 0 };
};

