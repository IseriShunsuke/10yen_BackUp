#pragma once
#include "KamataEngine.h"

class Coin
{
public:

	~Coin();

	void Initialize(KamataEngine::Model* model,KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	// 描画
	void Draw();

	KamataEngine::Vector3 SetPosition(KamataEngine::Vector3 position) { return worldTransform_.translation_ = position; }
	KamataEngine::Vector3 SetRotation(KamataEngine::Vector3 rotation) { return worldTransform_.rotation_ = rotation; }
	
private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;
};

