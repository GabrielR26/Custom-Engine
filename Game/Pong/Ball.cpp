
#include "Ball.h"
#include "PongManager.h"

Ball::Ball(PongManager* _manager)
	: Actor(new CircleShape(BALL_SIZE), VECTOR_ZERO, Color::White, nullptr)
{
	manager = _manager;
	leftBar = _manager->GetLeftBar();
	rightBar = _manager->GetRightBar();
	topBound = _manager->GetTopBound();
	bottomBound = _manager->GetBottomBound();
	bounceOnBar = false;

	soundBufferBounce = ResourceSubSystem::Instance()->LoadSound("Pong-sound.wav");
	soundBounce = new Sound(*soundBufferBounce);
}

void Ball::Start()
{
	Super::Start();

	SetPosition(Vector2f(Engine::GetMainWindowSize().x * 0.5f, Engine::GetMainWindowSize().y * 0.5f));
}

void Ball::Update(const float _deltaTime)
{
	Super::Update(_deltaTime);

	// Bounce on Borders
	if (Hit(topBound) || Hit(bottomBound))
	{
		soundBounce->play();
		velocity.y *= -1;
	}

	if (bounceOnBar)
		return;

	// Bounce on bars
	if (const optional<CollideDirection> _hitDirection = Hit(leftBar))
	{
		if (_hitDirection.value() == CollideDirection::Left)
			velocity.x *= -1;
		else if (_hitDirection.value() == CollideDirection::Top || _hitDirection.value() == CollideDirection::Bottom)
			velocity.y *= -1;
		BounceOnBar();
	}
	else if (const optional<CollideDirection> _hitDirection = Hit(rightBar))
	{
		if (_hitDirection.value() == CollideDirection::Right)
			velocity.x *= -1;
		else if (_hitDirection.value() == CollideDirection::Top || _hitDirection.value() == CollideDirection::Bottom)
			velocity.y *= -1;
		BounceOnBar();
	}
}

void Ball::Reset()
{
	SetPosition(Vector2f(Engine::GetMainWindowSize().x * 0.5f, Engine::GetMainWindowSize().y * 0.5f));
	velocity = VECTOR_ZERO;
}

void Ball::Launch()
{
	velocity = Vector2f(RAND_BOOL ? BALL_X_SPEED : -BALL_X_SPEED, RAND_BOOL ? BALL_Y_SPEED : -BALL_Y_SPEED);
}

void Ball::BounceOnBar()
{
	soundBounce->play();
	velocity *= 1.1f; // Increase speed after each hit
	bounceOnBar = true; // Prevent multiple bar collisions in a short time
	StartTimer(0.5f, [=]()
		{
			bounceOnBar = false;
		}
	);
}

void Ball::Destroy()
{
	rightBar = leftBar = nullptr;
	Super::Destroy();
}
