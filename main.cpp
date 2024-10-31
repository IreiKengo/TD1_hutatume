#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "1102_シュヴェルトライテ";

struct Vector2
{
	float x;
	float y;
};

struct Player
{
	Vector2 center;
	float radius;
	float speed;
	int isAlive;
};

struct Boss
{
	Vector2 center;
	float radius;

};


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	Player player =
	{
		600.0f,300.0f,16.0f,8.0f,true
	};

	Boss boss =
	{
		600.0f,150.0f,64.0f
	};



	enum Scene
	{
		TITLE,//タイトル
		RURU1,//ルール1
		RURU2,//ルール2
		STAGE1,//ステージ1
		STAGE2,//ステージ2
		GAMECLEAR,//ゲームクリア
		GAMEOVER//ゲームオーバー
	};
	int scene = TITLE;

	int ruru1;//ルール1
	ruru1 = Novice::LoadTexture("./Resources./images./TD.RURU1.png");
	int ruru2;//ルール2
	ruru2 = Novice::LoadTexture("./Resources./images./TD.RURU2.png");
	int stage1;//ステージ1
	stage1 = Novice::LoadTexture("./Resources./images./TD.STAGE1.png");
	int stage2;//ステージ2
	stage2 = Novice::LoadTexture("./Resources./images./TD.STAGE2.png");
	int gameClear;//ゲームクリア
	gameClear = Novice::LoadTexture("./Resources./images./TD.GAMECLEAR.png");
	int gameOver;//ゲームオーバー
	gameOver = Novice::LoadTexture("./Resources./images./TD.GAMEOVER.png");

	int playerGraph = Novice::LoadTexture("./Resources./images./player.png");

	int bossGraph = Novice::LoadTexture("./Resources./images./boss.png");

	int titleGraph = Novice::LoadTexture("./Resources./images./title.png");

	//float x = 0.0f;
	//float y = 0.0f;
	//float distance = 0.0f;






	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case TITLE://タイトル

			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)// スペースキーが押されたらシーンをルール1に切り替える
			{
				scene = RURU1;//ルール1
			}
			break;
		case RURU1://ルール1
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)// スペースキーが押されたらシーンをルール2に切り替える
			{
				scene = RURU2;//ルール2
			}
			break;
		case RURU2://ルール2
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)// スペースキーが押されたらシーンをルール1に切り替える
			{
				scene = RURU1;//ルール1
			}
			if (keys[DIK_BACKSPACE] != 0 && preKeys[DIK_BACKSPACE] == 0)// バックスペースキーが押されたらシーンをステージ1に切り替える
			{
				scene = STAGE1;//ステージ1
			}
			break;
		case STAGE1://ステージ1

			if (keys[DIK_W])
			{
				player.center.y -= player.speed;
			}

			if (keys[DIK_S])
			{
				player.center.y += player.speed;
			}

			if (keys[DIK_A])
			{
				player.center.x -= player.speed;
			}

			if (keys[DIK_D])
			{
				player.center.x += player.speed;
			}

			//右
			if (player.center.x + player.radius >= 1280.0f)
			{
				player.center.x = 1280.0f - player.radius;
			}

			//左
			if (player.center.x - player.radius <= 0.0f)
			{
				player.center.x = player.radius;
			}

			//下
			if (player.center.y + player.radius >= 720.0f)
			{
				player.center.y = 720.0f - player.radius;
			}

			//左
			if (player.center.y - player.radius <= 0.0f)
			{
				player.center.y = player.radius;
			}



			if (keys[DIK_BACKSPACE] != 0 && preKeys[DIK_BACKSPACE] == 0)// バックスペースキーが押されたらシーンをタイトルに切り替える
			{
				scene = TITLE;//タイトル
			}
			if (keys[DIK_1] != 0 && preKeys[DIK_1] == 0)// 1キーが押されたらシーンをステージ2に切り替える
			{
				scene = STAGE2;//ステージ2
			}
			break;
		case STAGE2://ステージ2

			if (keys[DIK_W])
			{
				player.center.y -= player.speed;
			}

			if (keys[DIK_S])
			{
				player.center.y += player.speed;
			}

			if (keys[DIK_A])
			{
				player.center.x -= player.speed;
			}

			if (keys[DIK_D])
			{
				player.center.x += player.speed;
			}



			//右
			if (player.center.x + player.radius >= 1280.0f)
			{
				player.center.x = 1280.0f - player.radius;
			}

			//左
			if (player.center.x - player.radius <= 0.0f)
			{
				player.center.x = player.radius;
			}

			//下
			if (player.center.y + player.radius >= 720.0f)
			{
				player.center.y = 720.0f - player.radius;
			}

			//左
			if (player.center.y - player.radius <= 0.0f)
			{
				player.center.y = player.radius;
			}






			if (keys[DIK_BACKSPACE] != 0 && preKeys[DIK_BACKSPACE] == 0)// バックスペースキーが押されたらシーンをタイトルに切り替える
			{
				scene = TITLE;//タイトル
			}
			if (keys[DIK_1] != 0 && preKeys[DIK_1] == 0)// 1キーが押されたらシーンをゲームクリアに切り替える
			{
				scene = GAMECLEAR;//ゲームクリア
			}
			if (keys[DIK_2] != 0 && preKeys[DIK_2] == 0)// 2キーが押されたらシーンをゲームオーバーに切り替える
			{
				scene = GAMEOVER;//ゲームオーバー
			}
			break;
		case GAMECLEAR://ゲームクリア
			if (keys[DIK_BACKSPACE] != 0 && preKeys[DIK_BACKSPACE] == 0)// バックスペースキーが押されたらシーンをタイトルに切り替える
			{
				scene = TITLE;//タイトル
			}
			break;
		case GAMEOVER://ゲームオーバー
			if (keys[DIK_BACKSPACE] != 0 && preKeys[DIK_BACKSPACE] == 0)// バックスペースキーが押されたらシーンをタイトルに切り替える
			{
				scene = TITLE;//タイトル
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case TITLE://タイトル
			Novice::DrawSprite(0, 0, titleGraph, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case RURU1://ルール1
			Novice::DrawSprite(0, 0, ruru1, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case RURU2://ルール2
			Novice::DrawSprite(0, 0, ruru2, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case STAGE1://ステージ1
			Novice::DrawSprite(0, 0, stage1, 1.0f, 1.0f, 0.0f, WHITE);


			//プレイヤー
			Novice::DrawSprite(static_cast<int>(player.center.x - player.radius), static_cast<int>(player.center.y - player.radius), playerGraph, 1.0f, 1.0f, 0.0f, WHITE);




			//ボス
			Novice::DrawSprite(static_cast<int>(boss.center.x - boss.radius), static_cast<int>(boss.center.y - boss.radius), bossGraph, 1.0f, 1.0f, 0.0f, WHITE);

			break;
		case STAGE2://ステージ2
			Novice::DrawSprite(0, 0, stage2, 1.0f, 1.0f, 0.0f, WHITE);

			//プレイヤー
			Novice::DrawSprite(static_cast<int>(player.center.x - player.radius), static_cast<int>(player.center.y - player.radius), playerGraph, 1.0f, 1.0f, 0.0f, WHITE);

			//ボス
			Novice::DrawSprite(static_cast<int>(boss.center.x - boss.radius), static_cast<int>(boss.center.y - boss.radius), bossGraph, 1.0f, 1.0f, 0.0f, WHITE);







			break;
		case GAMECLEAR://ゲームクリア
			Novice::DrawSprite(0, 0, gameClear, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case GAMEOVER://ゲームオーバー
			Novice::DrawSprite(0, 0, gameOver, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

