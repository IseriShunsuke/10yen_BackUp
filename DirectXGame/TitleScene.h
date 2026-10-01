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

	//ステージ
	KamataEngine::WorldTransform stageTransform;
	KamataEngine::WorldTransform stageTransform2;
	KamataEngine::WorldTransform stageTransform3;
	KamataEngine::WorldTransform stageTransform4;
	KamataEngine::WorldTransform stageTransform5;
	KamataEngine::Model* stageModel_;

	//10円
	KamataEngine::WorldTransform yenTransform;
	KamataEngine::Model* yenModel_;

	//背景
	KamataEngine::WorldTransform haikeiTransform;
	KamataEngine::Model* haikeiModel_;

	KamataEngine::Camera camera;
	
	KamataEngine::Vector3 cameraPosition;

	KamataEngine::Sprite* spriteUI_ = nullptr;

	uint32_t UItexture_;

	KamataEngine::Sprite* spriteTitleNameUI_ = nullptr;

	uint32_t nameUItexture_;

	float cameraSpeed;

	bool isFinish;

	float viewTimer;
	bool isView;

	bool isRolling;
	float waitTimer;
	int roop;

	uint32_t soundDataHandle;
	uint32_t voiceHandle;

	uint32_t SEDataHandle;
	uint32_t SEHandle;
};

