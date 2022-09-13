#pragma once

#include "DxLib.h"
#include <time.h>
#include "System.h"
#include <math.h>

class Player;

class Enemy
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 更新
	/// </summary>
	void Update(float x, float y, int Height, int Width);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// リスポン
	/// </summary>
	void Respon(float X, float Y, int Height, int Width);

	/// <summary>
	/// 動き
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void Move(float x, float y);
	void Attack(float x, float y);
	void Leave(float x, float y);

	VECTOR GetTranslation() { return translation; }
	float GetRadius() { return radius; }
	int GetFlag() { return aliveFlag; }
	int GetHP() { return HP; }
private:
	//敵のパラメータ
	VECTOR translation;
	float radius;
	//生存フラグ
	int aliveFlag;
	//移動フラグ
	int moveFlag;
	//敵発生タイマー
	float responTimer;
	//移動タイマー
	float moveTimer;

	//重力
	float yAdd;

	//体力
	int HP = 200;

	System* system_ = new System();
	Player* player_ = new Player();
};