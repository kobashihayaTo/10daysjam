#include "DxLib.h"
#include "Player.h"
#include "System.h"
// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2C_13_コバシ_ハヤト";

// ウィンドウ横幅
const int WIN_WIDTH = 1280;

// ウィンドウ縦幅
const int WIN_HEIGHT = 720;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言
	Player* player_ = new Player();
	player_->Initialize();

	System* system_ = new System();
	system_->Initialize();

	//シーン用変数
	int Scene = 0;
	
	int timer = 20;
	int timerFlag = 0;
	//プレイヤーのHP
	int HP;

	

	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		switch (Scene)
		{
		case 0://タイトル
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && Scene == 0 ||
				key & PAD_INPUT_1 && Scene == 0)
			{
				Scene = 1;
			}
			break;
		case 1://操作説明
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timerFlag == 1 ||
				key & PAD_INPUT_1 && timerFlag == 1)
			{
				Scene = 2;
				timerFlag = 0;
			}
			timer--;
			if (timer < 0) {
				timerFlag = 1;
			}
			break;

		case 2://ゲーム
			player_->Update(keys, oldkeys, system_->GetgameTimer(), system_->Getcount());
			system_->Update(player_->GetHP_X());
			HP = player_->GetHP_X();
			if (HP <= 10)
			{
				Scene = 4;
			}
			break;


		case 3://ゲームクリア

			break;

		case 4://ゲームオーバー

			break;
		}
	
		// 描画処理
		switch (Scene)
		{
		case 0://タイトル
			DrawBox(0, 0, 1280, 720, GetColor(255, 255, 0), true);
			break;

		case 1://操作説明
			DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
			break;

		case 2://ゲーム
			player_->Draw();
			system_->Draw(player_->Gettrans_X(), player_->Gettrans_Y(), player_->GetHP_X());

			break;

		case 3://ゲームクリア
			DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
			DrawFormatString(100, 120, GetColor(255, 255, 255), "Scene:%d", Scene);
			break;

		case 4://ゲームオーバー

			break;
		}

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
