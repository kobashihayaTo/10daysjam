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
	int floor = LoadGraph("floor.png");
	int second = LoadGraph("second.png");
	int pillar = LoadGraph("pillar.png");

	int enemy[6]; LoadDivGraph("enemy.png", 6, 6, 1, 64, 64, enemy, FALSE);
	int enemy2[3]; LoadDivGraph("enemy2.png", 3, 3, 1, 64, 64, enemy2, FALSE);

	int enemyBullet[4]; LoadDivGraph("enemy2_bullet.png", 4, 4, 1, 32, 32, enemyBullet, FALSE);

	int map = LoadGraph("map.png");
	int title = LoadGraph("TITLE.png");
	int manual = LoadGraph("manual.png");
	int manual2 = LoadGraph("taitle2.png");
	int gameclear = LoadGraph("gameclear.png");
	int gameover = LoadGraph("gameover.png");
	int Camel[3];
	LoadDivGraph("dron.png", 3, 3, 1, 64, 64, Camel);
	int Title_BGM;
	Title_BGM = LoadSoundMem("�����_2.mp3");
	ChangeVolumeSoundMem(255 * 30 / 100, Title_BGM);
	int Game_BGM = LoadSoundMem("MusMus-BGM-122.mp3");
	ChangeVolumeSoundMem(255 * 20 / 100, Game_BGM);
	int Over_BGM = LoadSoundMem("�Q�[���I�[�o�[.mp3");
	ChangeVolumeSoundMem(255 * 30 / 100, Over_BGM);
	int Clear_BGM = LoadSoundMem("���g���ȃQ�[���N���A��.mp3");
	ChangeVolumeSoundMem(255 * 30 / 100, Clear_BGM);
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
	int MAP;

	int enemyAnimation[3] = { 100,100 ,100 };
	int enemyCount[3] = { 0 ,0,0 };

	int AnimetionTimer = 8;
	int AnimetionCount = 1;
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

				if (CheckSoundMem(Title_BGM) == 1) {
					StopSoundMem(Title_BGM);
				}
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
				timerFlag = 0;
				timer = 65;
				Scene = 2;
			}

			break;
		case 2://����������̂Q
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{

				Scene = 3;
				timerFlag = 0;
				timer = 60;

			}
			break;

		case 3://�Q�[��
			
			DrawGraph(0, 0, map, true);
#pragma region �A�j���[�V�����Ǘ�
			//--------------�G1-----------------//
			if (enemyAnimation[0] > 0)
			{
				enemyAnimation[0] -= 10;
			}
			if (enemyAnimation[0] <= 0 && enemyCount[0] < 6)
			{
				enemyCount[0] += 1;
				enemyAnimation[0] = 100;
				if (enemyCount[0] > 5)
				{
					enemyCount[0] = 0;
				}
			}
			//---------------�G2----------------//
			if (enemyAnimation[1] > 0)
			{
				enemyAnimation[1] -= 10;
			}
			if (enemyAnimation[1] <= 0 && enemyCount[1] < 3)
			{
				enemyCount[1] += 1;
				enemyAnimation[1] = 100;
				if (enemyCount[1] > 2)
				{
					enemyCount[1] = 0;
				}
			}
			//---------------�G�e-----------------//
			if (enemyAnimation[2] > 0)
			{
				enemyAnimation[2] -= 10;
			}
			if (enemyAnimation[2] <= 0 && enemyCount[2] < 3)
			{
				enemyCount[2] += 1;
				enemyAnimation[2] = 100;
				if (enemyCount[2] > 2)
				{
					enemyCount[2] = 0;
				}
			}
#pragma endregion


			system_->Update(player_->GetHP_X());

			player_->Update(keys, oldkeys, system_->GetgameTimer(), system_->Getcount(), map_->ScrollX);

			player_->Collision(enemy_->GetFlag(), enemy_->GetTranslation().x, enemy_->GetTranslation().y, enemy_->GetRadius());

			player_->Oncollision(enemy_->GetTranslation().x, enemy_->GetTranslation().y, enemy_->GetRadius(), enemy_->GetFlag(),
				enemy2_->translation.x, enemy2_->translation.y, enemy2_->radius, enemy2_->aliveFlag, enemy_->GetHP(), enemy2_->HP);
			enemy_->Update(player_->Gettrans_X(), player_->Gettrans_Y(), WIN_HEIGHT, WIN_WIDTH);

			enemy2_->Update(WIN_HEIGHT, WIN_WIDTH, player_->Gettrans_X(), player_->Gettrans_Y(), player_->GetRadius(), player_->GetFlag(), player_->GetHP_X());
			map_->Update();
			// �`�揈��
			map_->Draw(floor, second, pillar);
			player_->Draw();
			enemy_->Draw(enemy[enemyCount[0]]);
			enemy2_->Draw(enemy2[enemyCount[1]], enemyBullet[enemyCount[2]]);

			HP = player_->GetHP_X();
			if (HP <= 10)
			{
				Scene = 5;
				if (CheckSoundMem(Game_BGM) == 1) {
					StopSoundMem(Game_BGM);
				}
			}
			MAP = map_->GetScrollX();
			if (MAP == 7680)
			{
				Scene = 4;
				if (CheckSoundMem(Game_BGM) == 1) {
					StopSoundMem(Game_BGM);
				}
			}
			break;


		case 4://�Q�[���N���A
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}
			if (CheckSoundMem(Clear_BGM) == 1) {
				StopSoundMem(Clear_BGM);
			}
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1) 
			{
				Scene = 0;
				timerFlag = 0;
				timer = 120;
				
			}
			
			break;

		case 5://�Q�[���I�[�o�[
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{
				Scene = 0;
				timerFlag = 0;
				timer = 120;
				
			}
			if (CheckSoundMem(Over_BGM) == 1) {
				StopSoundMem(Over_BGM);
			}
			break;
		}

		// �`�揈��
		switch (Scene)
		{
		case 0://�^�C�g��

			if(CheckSoundMem(Title_BGM) == 0) {
				PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK,true);
			}

			DrawGraph(0, 0, title, true);
			break;

		case 1://�������
			

			DrawGraph(0, 0, manual, true);
			break;

		case 2://����������̂Q
			DrawGraph(0, 0, manual2, true);
			break;
		case 3://�Q�[��
			if (CheckSoundMem(Game_BGM) == 0) {
				PlaySoundMem(Game_BGM, DX_PLAYTYPE_BACK, true);
			}
			if (AnimetionTimer >= 0)
			{
				AnimetionTimer--;
			}
			if (AnimetionTimer <= 0)
			{
				AnimetionTimer = 8;
				AnimetionCount += 1;
				if (AnimetionCount > 2)
				{
					AnimetionCount = 0;
				}
			}

			DrawGraph(WIN_WIDTH / 2, 680, Camel[AnimetionCount], true);
			player_->Draw();
			system_->Draw(player_->Gettrans_X(), player_->Gettrans_Y(), player_->GetHP_X());



			break;

		case 4://�Q�[���N���A
			DrawGraph(0, 0, gameclear, true);
			if (CheckSoundMem(Clear_BGM) == 0) {
				PlaySoundMem(Clear_BGM, DX_PLAYTYPE_BACK, true);
			}
			break;

		case 5://�Q�[���I�[�o�[
			if (CheckSoundMem(Over_BGM) == 0) {
				PlaySoundMem(Over_BGM, DX_PLAYTYPE_BACK, true);
			}
			DrawGraph(0, 0, gameover, true);
			break;
		}


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