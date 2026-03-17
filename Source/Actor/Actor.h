#pragma once

#include "Object/RenderObject.h"
#include "SubSystem/EventSubSystem.h"
#include "TriggerBox/TriggerBox.h"

// TODO add parent/children relationship (Transform, Enable, ...)

/// <summary>
/// Give collision's direction
/// </summary>
enum CollideDirection
{
	Top,
	Bottom,
	Left,
	Right
};

/// <summary>
/// Basic shaped class in CustomEngine
/// </summary>
class Actor : public RenderObject
{ 
	DECLARE_TYPE(Actor, RenderObject)

protected:
	unique_ptr<Shape> shape = nullptr;
	Vector2f velocity = Vector2f(0, 0);
	bool isCollidable = true;

public:
	// Actor
	inline Vector2f GetPosition() const { return shape->getPosition(); }
	inline void SetPosition(const Vector2f& _value) { shape->setPosition(_value); }
	inline Vector2f GetVelocity() const { return velocity; }
	inline void SetVelocity(const Vector2f& _value) { velocity = _value; }
	inline bool IsCollidable() const { return isCollidable; }
	inline void SetIsCollidable(const bool _value) { isCollidable = _value; }
	// Shape
	inline Shape* GetShape() const { return shape.get(); }
	inline Color GetColor() const { return shape->getFillColor(); }
	inline void SetColor(const Color& _value) { shape->setFillColor(_value); }
	// Bounding Box
	inline FloatRect GetBoundingBox() const { return shape->getGlobalBounds(); }
	inline float Left() const { return shape->getPosition().x - (shape->getGlobalBounds().size.x * 0.5f); }
	inline float Right() const { return shape->getPosition().x + (shape->getGlobalBounds().size.x * 0.5f); }
	inline float Top() const { return shape->getPosition().y - (shape->getGlobalBounds().size.y * 0.5f); }
	inline float Bottom() const { return shape->getPosition().y + (shape->getGlobalBounds().size.y * 0.5f); }

public:
	Actor(Shape* _shape, const Vector2f& _position, const bool _isRendered = true);
	Actor(Shape* _shape, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	Actor(Shape* _shape, const Vector2f& _position, Texture* _texture, const bool _isRendered = true);
	Actor(Shape* _shape, const Vector2f& _position, const Color& _color, Texture* _texture, const bool _isRendered = true);

	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Destroy() override;

	/// <summary>
	/// Test collision with another Actor 
	/// </summary>
	/// <param name="_other"> Actor to test collision </param>
	/// <returns> CollideDirection if hit, nullopt otherwise </returns>
	optional<CollideDirection> Hit(const Actor* _other);

	/// <summary>
	/// Move Actor with given offset
	/// </summary>
	/// <param name="_offset"> Offset to add on Actor's position </param>
	void Move(const Vector2f& _offset) { shape->move(_offset); }
	/// <summary>
	/// Rotate Actor with given angle
	/// </summary>
	/// <param name="_angle"> Angle to add on Actor's rotation </param>
	void Rotate(const Angle& _angle) { shape->rotate(_angle); }
	/// <summary>
	/// Scale Actor with given factor
	/// </summary>
	/// <param name="_factor"> Factor to add on Actor's scale </param>
	void Scale(const Vector2f& _factor) { shape->scale(_factor); }

	// Inherited via RenderObject
	void Render(RenderWindow* _window) override;
};

