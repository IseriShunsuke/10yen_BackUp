#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene()
{
	delete spriteTitle_;
}

void TitleScene::Initialize()
{
	textureHandle_ = TextureManager::Load("Title.png");

	spriteTitle_ = Sprite::Create(textureHandle_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	isFinish = false;
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		isFinish = true;
	}
}

void TitleScene::Draw()
{
	Sprite::PreDraw();
	spriteTitle_->Draw();
	Sprite::PostDraw();
}