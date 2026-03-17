#include "UI_Image.h"

UI_Image::UI_Image(const UI_Image& _other)
{
	texture = _other.texture;
	sprite = make_unique<Sprite>(*_other.sprite);
	isRendered = _other.isRendered;
}

UI_Image::UI_Image(const bool _isRendered)
	: UI_Image(new Texture(), VECTOR_CENTER, DEFAULT_IMAGE_SCALE, DEFAULT_IMAGE_COLOR, _isRendered)
{
}

UI_Image::UI_Image(Texture* _texture, const Vector2f& _position, const bool _isRendered)
	: UI_Image(_texture, _position, DEFAULT_IMAGE_SCALE, DEFAULT_IMAGE_COLOR, _isRendered)
{
}

UI_Image::UI_Image(Texture* _texture, const Vector2f& _position, const Vector2f& _scale, const bool _isRendered)
	: UI_Image(_texture, _position, _scale, DEFAULT_IMAGE_COLOR, _isRendered)
{
}

UI_Image::UI_Image(Texture* _texture, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Image(_texture, _position, DEFAULT_IMAGE_SCALE, _color, _isRendered)
{
}

UI_Image::UI_Image(Texture* _texture, const Vector2f& _position, const Vector2f& _scale, const Color& _color, const bool _isRendered)
	: UI(_isRendered)
{
	THROW_IF_NULLPTR(_texture);

	texture = _texture;
	sprite = make_unique<Sprite>(*texture);

	sprite->setOrigin(sprite->getGlobalBounds().getCenter());
	sprite->setPosition(_position);
	sprite->setScale(_scale);
	sprite->setColor(_color);
}

UI_Image::UI_Image(Sprite* _sprite, const Vector2f& _position, const bool _isRendered)
	: UI_Image(_sprite, _position, DEFAULT_IMAGE_SCALE, DEFAULT_IMAGE_COLOR, _isRendered)
{
}

UI_Image::UI_Image(Sprite* _sprite, const Vector2f& _position, const Vector2f& _scale, const bool _isRendered)
	: UI_Image(_sprite, _position, _scale, DEFAULT_IMAGE_COLOR, _isRendered)
{
}

UI_Image::UI_Image(Sprite* _sprite, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Image(_sprite, _position, DEFAULT_IMAGE_SCALE, _color, _isRendered)
{
}

UI_Image::UI_Image(Sprite* _sprite, const Vector2f& _position, const Vector2f& _scale, const Color& _color, const bool _isRendered)
	: UI(_isRendered)
{
	THROW_IF_NULLPTR(_sprite);

	sprite = make_unique<Sprite>(*_sprite);
	texture = &(sprite->getTexture());

	ResetOrigin();
	sprite->setPosition(_position);
	sprite->setScale(_scale);
	sprite->setColor(_color);
}

void UI_Image::ResetOrigin()
{
	Vector2f _origin = sprite->getLocalBounds().getCenter();
	sprite->setOrigin(_origin);
}

void UI_Image::Render(RenderWindow* _window)
{
	_window->draw(*sprite);
}

void UI_Image::Destroy()
{
	texture = nullptr;
	Super::Destroy();
}
