
#include "Actor.h"

Actor::Actor(Shape* _shape, const Vector2f& _position, const bool _isRendered)
	: Actor(_shape, _position, Color::White, nullptr, _isRendered)
{
}

Actor::Actor(Shape* _shape, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: Actor(_shape, _position, _color, nullptr, _isRendered)
{
}

Actor::Actor(Shape* _shape, const Vector2f& _position, Texture* _texture, const bool _isRendered)
	: Actor(_shape, _position, Color::White, _texture, _isRendered)
{
}

Actor::Actor(Shape* _shape, const Vector2f& _position, const Color& _color, Texture* _texture, const bool _isRendered)
	: RenderObject(_isRendered)
{
	THROW_IF_NULLPTR(_shape);

	shape.reset(_shape);
	velocity = VECTOR_ZERO;

	shape->setTexture(_texture);
	shape->setFillColor(_color);
	shape->setOrigin(shape->getGlobalBounds().getCenter());
	shape->setPosition(_position);
}

void Actor::Start()
{
	Super::Start();
}

void Actor::Update(const float _deltaTime)
{
	Super::Update(_deltaTime);

	shape->move(velocity);
}

void Actor::Destroy()
{
	Super::Destroy();
}

optional<CollideDirection> Actor::Hit(const Actor* _other)
{
	THROW_IF_NULLPTR(_other);

	if (!isCollidable || !_other->IsCollidable())
		return nullopt;

	FloatRect _thisBox = GetBoundingBox();
	FloatRect _otherBox = _other->GetBoundingBox();

	if (const optional<FloatRect> _intersection = _thisBox.findIntersection(_otherBox))
	{
		Vector2f _thisCenter = _thisBox.getCenter();
		Vector2f _interCenter = _intersection.value().getCenter();

		if (_interCenter.x < _thisCenter.x)
			return CollideDirection::Left;
		else if (_interCenter.x > _thisCenter.x)
			return CollideDirection::Right;
		else if (_interCenter.y < _thisCenter.y)
			return CollideDirection::Top;
		else if (_interCenter.y > _thisCenter.y)
			return CollideDirection::Bottom;
	}

	return nullopt;
}

void Actor::Render(RenderWindow* _window)
{
	_window->draw(*shape);
}
