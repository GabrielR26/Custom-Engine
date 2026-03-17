#pragma once

#include "Actor/Actor.h"
#include "Bar.h"

class PongManager;

#define BALL_X_SPEED 5.f
#define BALL_Y_SPEED 4.f
#define BALL_SIZE 7.5f

class Ball : public Actor
{
	DECLARE_TYPE(Ball, Actor)

	PongManager* manager = nullptr;
	SoundBuffer* soundBufferBounce = nullptr;
	Sound* soundBounce = nullptr;
	Bar* leftBar = nullptr;
	Bar* rightBar = nullptr;
	Actor* topBound = nullptr;
	Actor* bottomBound = nullptr;
	bool bounceOnBar = false;

public:
	Ball(PongManager* _manager);

	void Start() override;
	void Update(const float _deltaTime) override;

	void Reset();
	void Launch();
	void BounceOnBar();

	void Destroy() override;
};

