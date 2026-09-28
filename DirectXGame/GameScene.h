#pragma once
#include "KamataEngine.h"

class GameScene
{
public:
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

	void AllCollision();

	void MoveCoin();

	bool GetClear() { return isClear; };
	bool GetOver() { return isOver; };
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
	//ゴール
	KamataEngine::WorldTransform goalTransform;
	KamataEngine::Model* goalModel_;

	//背景
	KamataEngine::WorldTransform haikeiTransform;
	KamataEngine::Model* haikeiModel_;

	KamataEngine::Camera camera;
	//当たり判定
	bool isHit;
	bool isHit2;
	bool isHit3;
	bool isHit4;
	bool isHit5;

	float hitPower;
	float shotPower;
	float gravity;

	bool shot;
	bool hitWall;

	bool hitGoal;

	bool isClear;
	bool isOver;
	
	KamataEngine::Vector3 hitPosition_;
};

