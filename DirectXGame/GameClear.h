#pragma once
#include "KamataEngine.h"

class GameClear
{
public:
	~GameClear();

	void Initialize();

	void Update();

	void Draw();

	bool GetFinish() { return isFinish; }
private:
	KamataEngine::Sprite* spriteTitle_ = nullptr;

	uint32_t textureHandle_ = 0;

	bool isFinish = false; 
};

