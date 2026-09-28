#include "GameClear.h"

using namespace KamataEngine;

GameClear::~GameClear()
{
	delete spriteTitle_;
}

void GameClear::Initialize()
{
	textureHandle_ = TextureManager::Load("gameclear.png");

	spriteTitle_ = Sprite::Create(textureHandle_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	isFinish = false;
}

void GameClear::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_D))
	{
		isFinish = true;
	}
}

void GameClear::Draw()
{
	Sprite::PreDraw();
	spriteTitle_->Draw();
	Sprite::PostDraw();
}