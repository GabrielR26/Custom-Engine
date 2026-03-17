#pragma once

#include "UI.h"

#define DEFAULT_TEXT_FONT ResourceSubSystem::Instance()->GetBasicFont()
#define DEFAULT_TEXT_COLOR Color::White
#define DEFAULT_TEXT_CHARACTER_SIZE 20
#define DEFAULT_TEXT_STYLE Text::Regular
#define DEFAULT_TEXT "text"

/// <summary>
/// Class to display a text for UI
/// </summary>
class UI_Text final : public UI
{
	DECLARE_TYPE(UI_Text, UI)

private:
	const Font* font = nullptr;
	unique_ptr<Text> text = nullptr;

public:
	// Text
	inline Text* GetText() const { return text.get(); }
	inline const Font* GetFont() const { return font; }
	inline string GetString() const { return text->getString(); }
	inline Color GetColor() const { return text->getFillColor(); }
	inline size_t GetCharacterSize() const { return text->getCharacterSize(); }
	inline void SetFont(Font* _font) { font = _font; text->setFont(*font); }
	inline void SetText(const string& _string) { text->setString(_string); ResetOrigin(); }
	inline void SetColor(const Color& _color) { text->setFillColor(_color); }
	inline void SetCharacterSize(const size_t _characterSize) { text->setCharacterSize(_characterSize); ResetOrigin(); }

public:
	UI_Text(const UI_Text& _other);
	UI_Text(const string& _string, const bool _isRendered = true);

	UI_Text(const string& _string, const Vector2f& _position, const bool _isRendered = true);
	UI_Text(const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Text(const string& _string, const Vector2f& _position, const int _characterSize, const bool _isRendered = true);
	UI_Text(const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const uint32_t _styles, const bool _isRendered = true);

	UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const bool _isRendered = true);
	UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const int _characterSize, const bool _isRendered = true);
	UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const bool _isRendered = true);
	UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const uint32_t _styles, const bool _isRendered = true);

	// Inherited via UI
	void Render(RenderWindow* _window) override;

	// Inherited via Object
	void Destroy() override;
	string ToString() override;

private:
	// Inherited via UI
	void ResetOrigin() override;
};
