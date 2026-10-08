#include "Stage.h"

using namespace KamataEngine;

Stage::~Stage()
{
	delete model_;
}

void Stage::Initialize(Model* model, Camera* camera, const Vector3& position)
{

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = { 1.0f,1.0f,1.0f };
	worldTransform_.rotation_ = { 0.0f,0.0f,0.0f };

	camera_ = camera;

	model_ = model;
}

void Stage::Update()
{
	worldTransform_.UpdateMatrix();
}

void Stage::Draw()
{
	model_->Draw(worldTransform_, *camera_);
}

