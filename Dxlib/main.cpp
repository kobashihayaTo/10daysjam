#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "System.h"
#include "Map.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "";

// �E�B���h�E����
const int WIN_WIDTH = 1280;

// �E�B���h�E�c��
const int WIN_HEIGHT = 768;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	int floor = LoadGraph("Resource/floor.png");
	int second = LoadGraph("Resource/second.png");
	int pillar = LoadGraph("Resource/pillar.png");

	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	System* system_ = new System();
	system_->Initialize();

	Map* map_ = new Map();
	map_->Initialize();

	Player* player_ = new Player();
	player_->Initialize();

	Enemy* enemy_ = new Enemy();
	enemy_->Initialize();

	Enemy2* enemy2_ = new Enemy2();
	enemy2_->Initialize(WIN_HEIGHT, WIN_WIDTH);

	//�V�[���p�ϐ�
	int Scene = 0;

	int timer = 60;
	int timerFlag = 0;

	int HP;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };


	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
 		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		switch (Scene)
		{
		case 0://�^�C�g��
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{
				player_->Reset();

				Scene = 1;
				timerFlag = 0;
				timer = 60;
			}
			break;
		case 1://�������
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{

				Scene = 2;
				timerFlag = 0;
				timer = 60;
			}

			break;

		case 2://�Q�[��
			system_->Update(player_->GetHP_X());
			player_->Update(keys, oldkeys, system_->GetgameTimer(), system_->Getcount(), map_->ScrollX);
			player_->Collision(enemy_->GetFlag(), enemy_->GetTranslation().x, enemy_->GetTranslation().y, enemy_->GetRadius());
			player_->Oncollision(enemy_->GetTranslation().x, enemy_->GetTranslation().y, enemy_->GetRadius(), enemy_->GetFlag(), enemy2_->translation.x, enemy2_->translation.y, enemy2_->radius, enemy2_->aliveFlag, enemy_->GetHP(), enemy2_->HP);
			enemy_->Update(player_->Gettrans_X(), player_->Gettrans_Y(), WIN_HEIGHT, WIN_WIDTH);
			enemy2_->Update(WIN_HEIGHT, WIN_WIDTH, player_->Gettrans_X(), player_->Gettrans_Y(), player_->GetRadius(), player_->GetFlag(), player_->GetHP_X());
			map_->Update();
			// �`�揈��
			map_->Draw(floor, second, pillar);
			player_->Draw();
			enemy_->Draw();
			enemy2_->Draw();

			HP = player_->GetHP_X();
			if (HP <= 10)
			{
				Scene = 4;
			}

			break;


		case 3://�Q�[���N���A

			break;

		case 4://�Q�[���I�[�o�[
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{
				player_->Reset();

				Scene = 0;
				timerFlag = 0;
				timer = 120;
			}
			break;
		}

		// �`�揈��
		switch (Scene)
		{
		case 0://�^�C�g��
			DrawBox(0, 0, 1280, 720, GetColor(255, 255, 0), true);
			break;

		case 1://�������
			DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
			break;

		case 2://�Q�[��
			player_->Draw();
			system_->Draw(player_->Gettrans_X(), player_->Gettrans_Y(), player_->GetHP_X());

			break;

		case 3://�Q�[���N���A

			break;

		case 4://�Q�[���I�[�o�[
			DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
			DrawFormatString(100, 120, GetColor(255, 255, 255), "Scene:%d", Scene);
			break;
		}

		// �`�揈��

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}