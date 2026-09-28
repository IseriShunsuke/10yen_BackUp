#include "GameScene.h"
#include "HitBox.h"
using namespace KamataEngine;


GameScene::~GameScene()
{
	delete stageModel_;
	delete yenModel_;

	goalModel_;
}

void GameScene::Initialize()
{
	//ステージ
	stageModel_ = Model::CreateFromOBJ("stage_kari");
	stageTransform.Initialize();
	stageTransform.translation_ = { -9.0f,5.0f,0.0f };
	stageTransform.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform2.Initialize();
	stageTransform2.translation_ = { 6.0f,-7.0f,0.0f };
	stageTransform2.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform2.rotation_ = { 0.0f,0.0f,0.5f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform3.Initialize();
	stageTransform3.translation_ = { -12.0f,-20.0f,0.0f };
	stageTransform3.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform3.rotation_ = { 0.0f,0.0f,0.1f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform4.Initialize();
	stageTransform4.translation_ = { 6.0f,-30.0f,0.0f };
	stageTransform4.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform4.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform5.Initialize();
	stageTransform5.translation_ = { -18.0f,-44.0f,0.0f };
	stageTransform5.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform5.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	//10円
	yenModel_ = Model::CreateFromOBJ("coin");
	yenTransform.Initialize();
	yenTransform.translation_ = { -3.0f,16.0f,0.0f };
	yenTransform.scale_ = { 1.0f,1.0f,1.0f };
	yenTransform.rotation_ = { 0.0f,0.0f,0.0f };

	//ゴール
	goalModel_ = Model::CreateFromOBJ("cube");
	goalTransform.Initialize();
	goalTransform.translation_ = { 6.0f,-44.0f,0.0f };
	goalTransform.scale_ = { 1.0f,1.0f,1.0f };
	goalTransform.rotation_ = { 0.0f,0.0f,0.0f };

	//背景
	haikeiModel_ = Model::CreateFromOBJ("haikei");
	haikeiTransform.Initialize();
	haikeiTransform.translation_ = { -5.0f,0.0f,8.0f };
	haikeiTransform.scale_ = { 0.6f,1.5f,1.0f };
	haikeiTransform.rotation_ = { 0.0f,3.14f,0.0f };


	//カメラ
	camera.Initialize();
	camera.rotation_ = { 0.0f,0.0f,0.0f };
	camera.translation_ = { 0.0f, 5.0f,-50.0f };

	camera.UpdateMatrix();
	camera.TransferMatrix();

	isHit = true;

	hitPosition_ = { 0.0f,0.0f,0.0f };
	gravity = 0.1f;

	shot = false;
	hitWall = false;

	isClear = false;
	isOver = false;
}

void GameScene::Update()
{
	AllCollision();

	MoveCoin();


	if (yenTransform.translation_.x <= -20.0f)
	{
		hitWall = true;
		yenTransform.translation_.x = -20.0f;
	}

	else if (yenTransform.translation_.x > 10.0f)
	{
		hitWall = true;
		yenTransform.translation_.x = 10.0f;
	}
	else
	{
		hitWall = false;
	}

	if (hitWall)
	{
		
		shot = false;
		if (isHit)
		{
			gravity = 0.0f;
			
		}
		if (isHit2)
		{
			hitPower = 0.0f;
		}
		if (isHit3)
		{
			gravity = 0.0f;

		}
		if (isHit4)
		{
			hitPower = 0.0f;
		}
		if (isHit5)
		{
			gravity = 0.0f;
			hitPower = 0.0f;

		}


	}

	if (hitPower == 0)
	{
		shot = false;
	}

	if (!isHit2 && !isHit && !isHit3 && !isHit4 && !isHit5)
	{
		hitPosition_.y = yenTransform.translation_.y;
		yenTransform.translation_.y -= gravity;//重力
	}

	if (yenTransform.translation_.y <= 0.0f)
	{
		camera.translation_.y = yenTransform.translation_.y;
	}

	if (yenTransform.translation_.y < -49.0f)
	{
		isOver = true;
	}

	if (camera.translation_.y <= -30.0f)
	{
		camera.translation_.y = -30.0f;
	}

	stageTransform.UpdateMatrix();
	stageTransform2.UpdateMatrix();
	stageTransform3.UpdateMatrix();
	stageTransform4.UpdateMatrix();
	stageTransform5.UpdateMatrix();
	yenTransform.UpdateMatrix();
	goalTransform.UpdateMatrix();
	haikeiTransform.UpdateMatrix();

	camera.UpdateMatrix();

}

void GameScene::MoveCoin()
{
	if (Input::GetInstance()->PushKey(DIK_A)) {

		hitPower -= 0.01f;
		if (hitPower <= -1.0f)
		{
			hitPower = -1.0f;
		}

	}
	else if (Input::GetInstance()->PushKey(DIK_D)) {

		
		hitPower += 0.01f;
		if (hitPower >= 1.0f)
		{
			hitPower = 1.0f;
		}

	}
	else
	{
		shotPower = hitPower;
		if (shotPower != 0.0f)
		{
			shot = true;

		}
		else
		{
			hitPower = 0.0f;
		}

	}

	if (shot)
	{

		yenTransform.translation_.x += shotPower * 1.0f;
		if (shotPower > 0.0f)
		{
			shotPower -= 0.1f;
			if (shotPower <= 0)
			{
				hitPower = 0.0f;
				shot = false;
			}
		}
		if (shotPower < 0.0f)
		{
			shotPower += 0.1f;
			if (shotPower >= 0)
			{
				hitPower = 0.0f;
				shot = false;
			}
		}

		if (shotPower == 0)
		{
			hitPower = 0.0f;
			shot = false;
		}


		if (isHit || isHit2 || isHit3 || isHit4 || isHit5)
		{
			yenTransform.translation_.y += 1.0f;
		}

		

		gravity = 0.1f;
	}



}

void GameScene::AllCollision()
{
	isHit = IsCollisionStage(yenTransform, stageTransform);
	isHit2 = IsCollisionStage(yenTransform, stageTransform2);
	isHit3 = IsCollisionStage(yenTransform, stageTransform3);
	isHit4 = IsCollisionStage(yenTransform, stageTransform4);
	isHit5 = IsCollisionStage(yenTransform, stageTransform5);

	hitGoal = IsCollisionGoal(yenTransform, goalTransform);


	if (isHit)
	{
		float angle = stageTransform.rotation_.z;
		float speed = 0.1f;

		// ステージの接線方向
		Vector2 dir = {
			std::cos(angle),
			std::sin(angle)
		};

		yenTransform.translation_.x -= dir.x * speed;
		if (!hitWall)
		{
			yenTransform.translation_.y -= dir.y * speed;
		}
	}
	else if (isHit2)
	{
		float angle = stageTransform2.rotation_.z;
		float speed = 0.1f;

		// ステージの接線方向
		Vector2 dir = {
			std::cos(angle),
			std::sin(angle)
		};

		yenTransform.translation_.x -= dir.x * speed;
		if (!hitWall)
		{
			yenTransform.translation_.y -= dir.y * speed;
		}

	}
	else if (isHit3)
	{
		float angle = stageTransform3.rotation_.z;
		float speed = 0.1f;

		// ステージの接線方向
		Vector2 dir = {
			std::cos(angle),
			std::sin(angle)
		};

		yenTransform.translation_.x -= dir.x * speed;
		if (!hitWall)
		{
			yenTransform.translation_.y -= dir.y * speed;
		}

	}
	else if (isHit4)
	{
		float angle = stageTransform4.rotation_.z;
		float speed = 0.1f;

		// ステージの接線方向
		Vector2 dir = {
			std::cos(angle),
			std::sin(angle)
		};

		yenTransform.translation_.x -= dir.x * speed;
		if (!hitWall)
		{
			yenTransform.translation_.y -= dir.y * speed;
		}

	}
	else if (isHit5)
	{
		float angle = stageTransform5.rotation_.z;
		float speed = 0.1f;

		// ステージの接線方向
		Vector2 dir = {
			std::cos(angle),
			std::sin(angle)
		};

		yenTransform.translation_.x -= dir.x * speed;
		if (!hitWall)
		{
			yenTransform.translation_.y -= dir.y * speed;
		}

	}

	if (hitGoal)
	{
		isClear = true;
	}
}

void GameScene::Draw()
{
	stageModel_->Draw(stageTransform, camera);
	stageModel_->Draw(stageTransform2, camera);
	stageModel_->Draw(stageTransform3, camera);
	stageModel_->Draw(stageTransform4, camera);
	stageModel_->Draw(stageTransform5, camera);
	yenModel_->Draw(yenTransform, camera);
	goalModel_->Draw(goalTransform, camera);
	haikeiModel_->Draw(haikeiTransform,camera);
}
