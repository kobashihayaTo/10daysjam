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
	/// ������
	/// </summary>
	void Initialize();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update(float x, float y, int Height, int Width);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���X�|��
	/// </summary>
	void Respon(float X, float Y, int Height, int Width);

	/// <summary>
	/// ����
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
	//�G�̃p�����[�^
	VECTOR translation;
	float radius;
	//�����t���O
	int aliveFlag;
	//�ړ��t���O
	int moveFlag;
	//�G�����^�C�}�[
	float responTimer;
	//�ړ��^�C�}�[
	float moveTimer;

	//�d��
	float yAdd;

	//�̗�
	int HP = 200;

	System* system_ = new System();
	Player* player_ = new Player();
};