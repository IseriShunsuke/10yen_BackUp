#pragma once
#include "KamataEngine.h"
#include <cmath>

bool IsCollisionStage(KamataEngine::WorldTransform& coin, KamataEngine::WorldTransform& stage);
bool IsCollisionGoal(const KamataEngine::WorldTransform& coin, const KamataEngine::WorldTransform& goal);

static inline const float kWidth = 1.0f;
static inline const float kHeight = 1.0f;

class HitBox
{
public:

private:
	
};

