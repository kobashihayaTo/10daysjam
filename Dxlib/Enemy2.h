#pragma once
#include "DxLib.h"
#include "EnemyBullet.h"
#include <math.h>
enum class Phase2 {
	Move,	//�ړ�
	Attack,	//�U��
	Attack2,//�U��2
	Leave	//���E
};

class Enemy2
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(int Height, int Width);
	/// <summary>
	/// �X�V
	/// </summary>
	void Update(int Height, int Width, float playerX, float playerY, int playerRadius, int playerFlag, int hp);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw(int graphHandle, int bulletHandle);

	/// <summary>
	/// ���X�|��
	/// </summary>
	void Respon();

	void Move(int Height, int Width);
	void Attack(int Height, int Width);
	void Attack2(int Height, int Width, float x, float y);
	void Leave(int Height, int Width);
	//�t�F�[�Y
	Phase2 phase_ = Phase2::Move;
	EnemyBullet* bullet = new EnemyBullet();

	//���x
	float speed;
	//2�Ԗڂ̓G�p�����[�^�[
	VECTOR translation;
	float radius;

	//�����t���O
	int aliveFlag;
	//�����t���O
	int seeFlag;

	//�s���^�C�}�[
	int moveTimer;;
	//���X�|���^�C�}�[
	float responTimer;
	//�������n�߂�^�C�}�[
	float defSpeedTimer;
	//�U�����n�߂�^�C�}�[
	float attackTimer;

	int HP;
};