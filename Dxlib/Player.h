#pragma once
#include "DxLib.h"
#include "math.h"
#include "vector"

#include"PlayerBullet.h"
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

private:

	VECTOR translation;

	float radius = 20.0f;
	float move = 5;
	float GetPlayertrans_ = 100.0f;

	int jflag = false;
	int y_temp = 0;
	int y_prev = 0;
	int jampChange = 25;

	int dflag = false;


};

