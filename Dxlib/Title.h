#pragma once

#include "DxLib.h"

class TitleScene
{
public://�����o�֐�

	/// <summary>
	/// �R���X�g�N���^
	/// </summary>
	TitleScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TitleScene();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	int GetChangeFlag() { return changeFlag_; }
private:

	int changeFlag_ = false;

};

