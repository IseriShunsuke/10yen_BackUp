#include "GameOver.h"

using namespace KamataEngine;

GameOver::~GameOver()
{
	delete spriteTitle_;
}

void GameOver::Initialize()
{
	textureHandle_ = TextureManager::Load("gameover.png");

	spriteTitle_ = Sprite::Create(textureHandle_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	isFinish = false;
}

void GameOver::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_D))
	{
		isFinish = true;
	}
}

void GameOver::Draw()
{
	Sprite::PreDraw();
	spriteTitle_->Draw();
	Sprite::PostDraw();
}