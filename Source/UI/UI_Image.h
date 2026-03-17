#pragma once

#include "UI.h"

#define DEFAULT_IMAGE_SCALE Vector2f(1.f, 1.f)
#define DEFAULT_IMAGE_COLOR Color::White

/// <summary>
/// Class to display an image for UI
/// </summary>
class UI_Image final : public UI
{
	DECLARE_TYPE(UI_Image, UI)

private:
	const Texture* texture = nullptr;
	unique_ptr<Sprite> sprite = nullptr;

public:
	inline Sprite* GetSprite() { return sprite.get(); }
	inline const Texture* GetTexture() const { return texture; }
	inline void SetTexture(Texture* _texture)
	{
		texture = _texture;
		sprite->setTexture(*texture, true);
		ResetOrigin();
	}

public:
	UI_Image(const UI_Image& _other);

	UI_Image(const bool _isRendered = true);
	UI_Image(Texture* _texture, const Vector2f& _position, const bool _isRendered = true);
	UI_Image(Texture* _texture, const Vector2f& _position, const Vector2f& _scale, const bool _isRendered = true);
	UI_Image(Texture* _texture, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Image(Texture* _texture, const Vector2f& _position, const Vector2f& _scale, const Color& _color, const bool _isRendered = true);

	UI_Image(Sprite* _sprite, const Vector2f& _position, const bool _isRendered = true);
	UI_Image(Sprite* _sprite, const Vector2f& _position, const Vector2f& _scale, const bool _isRendered = true);
	UI_Image(Sprite* _sprite, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Image(Sprite* _sprite, const Vector2f& _position, const Vector2f& _scale, const Color& _color, const bool _isRendered = true);

	// Inherited via UI
	void Render(RenderWindow* _window) override;

	// Inherited via Object
	void Destroy() override;

private:
	// Inherited via UI
	void ResetOrigin() override;
};

