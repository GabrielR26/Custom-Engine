
#include "Bar.h"
#include "PongManager.h"

Bar::Bar(PongManager* _manager, const bool _left)
	: Actor(new RectangleShape({ BAR_WIDTH, BAR_HEIGHT }), VECTOR_ZERO, Color::White, nullptr)
{
	manager = _manager;
	left = _left;
	if (left)
		SetPosition(Vector2f(BAR_PADDING, Engine::GetMainWindowSize().y * 0.5f));
	else
		SetPosition(Vector2f(Engine::GetMainWindowSize().x - BAR_PADDING, Engine::GetMainWindowSize().y * 0.5f));
}

void Bar::Start()
{
	Super::Start();

	manager->OnGameStart()->AddListener(this, &Bar::EnableMove);
}

void Bar::Update(const float _deltaTime)
{
	Super::Update(_deltaTime);

	if (!canMove)
		return;

	// Move the bar based on user input
	Vector2u _windowSize = Engine::GetMainWindowSize();
	if (Keyboard::isKeyPressed(left ? Keyboard::Scan::W : Keyboard::Scan::Up))
	{
		if (GetPosition().y - (BAR_HEIGHT * 0.5f) > 0.f)
			Move(VECTOR_Y * -BAR_SPEED * _deltaTime * 10.f);
	}
	else if (Keyboard::isKeyPressed(left ? Keyboard::Scan::S : Keyboard::Scan::Down))
	{
		if (GetPosition().y + (BAR_HEIGHT * 0.5f) < _windowSize.y)
			Move(VECTOR_Y * BAR_SPEED * _deltaTime * 10.f);
	}
}

void Bar::EnableMove()
{
	canMove = true;
}
