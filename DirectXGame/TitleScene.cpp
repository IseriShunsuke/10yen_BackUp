#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene()
{
	delete spriteTitleNameUI_;
	delete spriteUI_;
	delete stageModel_;
	delete haikeiModel_;
	delete yenModel_;
}

void TitleScene::Initialize()
{
	stageModel_ = Model::CreateFromOBJ("stage_kari");
	stageTransform.Initialize();
	stageTransform.translation_ = { -12.0f,5.0f,9.0f };
	stageTransform.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform2.Initialize();
	stageTransform2.translation_ = { 6.0f,-7.0f,9.0f };
	stageTransform2.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform2.rotation_ = { 0.0f,0.0f,0.5f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform3.Initialize();
	stageTransform3.translation_ = { -12.0f,-20.0f,9.0f };
	stageTransform3.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform3.rotation_ = { 0.0f,0.0f,0.1f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform4.Initialize();
	stageTransform4.translation_ = { 6.0f,-30.0f,9.0f };
	stageTransform4.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform4.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	stageTransform5.Initialize();
	stageTransform5.translation_ = { -18.0f,-44.0f,9.0f };
	stageTransform5.scale_ = { 1.0f,1.0f,1.0f };
	stageTransform5.rotation_ = { 0.0f,0.0f,0.2f };//0.0 右斜め上　//2.0~左斜め上

	//10円
	yenModel_ = Model::CreateFromOBJ("coin");
	yenTransform.Initialize();
	yenTransform.translation_ = { -5.0f,16.0f,-10.0f };
	yenTransform.scale_ = { 1.0f,1.0f,1.0f };
	yenTransform.rotation_ = { 0.0f,0.0f,0.0f };

	//背景
	haikeiModel_ = Model::CreateFromOBJ("haikei");
	haikeiTransform.Initialize();
	haikeiTransform.translation_ = { -5.0f,0.0f,8.0f };
	haikeiTransform.scale_ = { 0.6f,1.5f,1.0f };
	haikeiTransform.rotation_ = { 0.0f,3.14f,0.0f };

	camera.Initialize();
	camera.rotation_ = { 0.0f,0.0f,0.0f };
	camera.translation_ = { 0.0f, 0.0f,0.0f };

	cameraPosition = { -5.0f,0.0f,-25.0f };

	UItexture_ = TextureManager::Load("TitleUI.png");

	spriteUI_ = Sprite::Create(UItexture_, { 640.0f, 580.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	nameUItexture_ = TextureManager::Load("TitleNameUI.png");

	spriteTitleNameUI_ = Sprite::Create(nameUItexture_, { 640.0f, 270.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	soundDataHandle = Audio::GetInstance()->LoadWave("kasumisou.wav");

	voiceHandle = Audio::GetInstance()->PlayWave(soundDataHandle, true);

	SEDataHandle = Audio::GetInstance()->LoadWave("pushBotan.wav");

	

	isFinish = false;
	cameraSpeed = 0.1f;
	roop = 0;
	viewTimer = 0.0f;
	isView = false;
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		isFinish = true;

		SEHandle = Audio::GetInstance()->PlayWave(SEDataHandle, true);

		Audio::GetInstance()->StopWave(soundDataHandle);
		
	}
	
	viewTimer += 1.0f / 60.0f;

	if (viewTimer > 0.5f && viewTimer <= 1.5f)
	{
		isView = true;
	}
	if (viewTimer > 1.5f)
	{
		isView = false;
		viewTimer = 0.0f;
	}

	if (!isRolling)
	{
		waitTimer += 1.0f / 60.0f;
		yenTransform.rotation_.y += 0.1f;
	}
	if (isRolling)
	{
		yenTransform.translation_.x += 0.1f;
		yenTransform.rotation_.z -= 0.03f;
		if (yenTransform.translation_.x >= 12.0f)
		{
			yenTransform.translation_.x = -21.0f;
			roop++;
		}
		if (roop >= 2 && yenTransform.translation_.x >= -5.0f)
		{
			isRolling = false;
		}
	}

	if (waitTimer >= 20.0f)
	{
		waitTimer = 0.0f;
		roop = 0;
		yenTransform.rotation_.y = 0.0f;
		isRolling = true;
	}

	cameraPosition.y -= cameraSpeed;

	yenTransform.translation_.y = cameraPosition.y +4.5f;

	if (cameraPosition.y <= -38.0f)
	{
		cameraSpeed = -cameraSpeed;
	}

	if (cameraPosition.y >= 10.0f)
	{
		cameraSpeed = -cameraSpeed;
	}

	camera.translation_ = cameraPosition;

	stageTransform.UpdateMatrix();
	stageTransform2.UpdateMatrix();
	stageTransform3.UpdateMatrix();
	stageTransform4.UpdateMatrix();
	stageTransform5.UpdateMatrix();

	yenTransform.UpdateMatrix();

	haikeiTransform.UpdateMatrix();

	camera.UpdateMatrix();

	camera.TransferMatrix();


}

void TitleScene::Draw()
{
	stageModel_->Draw(stageTransform, camera);
	stageModel_->Draw(stageTransform2, camera);
	stageModel_->Draw(stageTransform3, camera);
	stageModel_->Draw(stageTransform4, camera);
	stageModel_->Draw(stageTransform5, camera);

	haikeiModel_->Draw(haikeiTransform, camera);

	yenModel_->Draw(yenTransform, camera);

	Sprite::PreDraw();
	if (isView)
	{
		spriteUI_->Draw();
	}
	spriteTitleNameUI_->Draw();
	Sprite::PostDraw();
}