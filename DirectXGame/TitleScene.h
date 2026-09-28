#pragma once
#include "KamataEngine.h"

class TitleScene
{
public:
	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	bool GetFinish() { return isFinish; }
private:
	KamataEngine::Sprite* spriteTitle_ = nullptr;

	uint32_t textureHandle_ = 0;

	bool isFinish;
};

