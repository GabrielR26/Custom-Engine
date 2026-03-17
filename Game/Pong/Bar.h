#pragma once

#include "Actor/Actor.h"

class PongManager;

#define BAR_PADDING 50.f
#define BAR_WIDTH 25.f
#define BAR_HEIGHT 100.f
#define BAR_SPEED 30.f

class Bar : public Actor
{
	DECLARE_TYPE(Bar, Actor)

	PongManager* manager = nullptr;
	bool left;
	bool canMove = false;

public:
	Bar(PongManager* _manager, const bool _left);

	void Start() override;
	void Update(const float _deltaTime) override;

	void EnableMove();
};

