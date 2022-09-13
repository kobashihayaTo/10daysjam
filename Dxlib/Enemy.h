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
	void Draw(int graphHandle);

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
	void Attack2(float x, float y);
	void Hide(float x, float y);
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
	int seeFlag;
	//�����t���O
	int aliveFlag;
	//�ړ��t���O
	int moveFlag;
	//�W�����v�t���O
	int jumpFlag;
	//�B���t���O
	int hideFlag;
	//�B���^�C�}�[
	float hideTimer;
	//�G�����^�C�}�[
	float responTimer;
	//�W�����v�^�C�}�[
	float jumpTimer;
	//�ړ��^�C�}�[
	float moveTimer;

	//�d��
	float yAdd;

	//�̗�
	int HP = 200;

	System* system_ = new System();
};