#include "Coin.h"

using namespace KamataEngine;

Coin::~Coin()
{
}

void Coin::Initialize(Model* model, Camera* camera, const Vector3& position)
{

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = { 1.0f,1.0f,1.0f };
	worldTransform_.rotation_ = { 0.0f,0.0f,0.0f };

	camera_ = camera;

	model_ = model;
}

void Coin::Update()
{
	worldTransform_.UpdateMatrix();
}

void Coin::Draw()
{
	model_->Draw(worldTransform_, *camera_);
}
