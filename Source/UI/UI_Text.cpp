
#include "UI_Text.h"
#include "SubSystem/ResourceSubSystem.h"

UI_Text::UI_Text(const UI_Text& _other)
{
	font = _other.font;
	text = make_unique<Text>(*_other.text);
	isRendered = _other.isRendered;
}

UI_Text::UI_Text(const string& _string, const bool _isRendered)
	: UI_Text(DEFAULT_TEXT_FONT, _string, VECTOR_CENTER, DEFAULT_TEXT_COLOR, DEFAULT_TEXT_CHARACTER_SIZE, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const string& _string, const Vector2f& _position, const bool _isRendered)
	: UI_Text(DEFAULT_TEXT_FONT, _string, _position, DEFAULT_TEXT_COLOR, DEFAULT_TEXT_CHARACTER_SIZE, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Text(DEFAULT_TEXT_FONT, _string, _position, _color, DEFAULT_TEXT_CHARACTER_SIZE, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const string& _string, const Vector2f& _position, const int _characterSize, const bool _isRendered)
	: UI_Text(DEFAULT_TEXT_FONT, _string, _position, DEFAULT_TEXT_COLOR, _characterSize, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const uint32_t _styles, const bool _isRendered)
	: UI_Text(DEFAULT_TEXT_FONT, _string, _position, _color, _characterSize, _styles, _isRendered)
{
}

UI_Text::UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const bool _isRendered)
	: UI_Text(_font, _string, _position, DEFAULT_TEXT_COLOR, DEFAULT_TEXT_CHARACTER_SIZE, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Text(_font, _string, _position, _color, DEFAULT_TEXT_CHARACTER_SIZE, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const int _characterSize, const bool _isRendered)
	: UI_Text(_font, _string, _position, DEFAULT_TEXT_COLOR, _characterSize, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const bool _isRendered)
	: UI_Text(_font, _string, _position, _color, _characterSize, DEFAULT_TEXT_STYLE, _isRendered)
{
}

UI_Text::UI_Text(const Font* _font, const string& _string, const Vector2f& _position, const Color& _color, const int _characterSize, const uint32_t _styles, const bool _isRendered)
	: UI(_isRendered)
{
	THROW_IF_NULLPTR(_font);

	font = _font;
	text = make_unique<Text>(*font, _string, _characterSize);
	text->setFillColor(_color);
	text->setStyle(_styles);

	ResetOrigin();
	text->setPosition(_position);
}

void UI_Text::ResetOrigin()
{
	text->setOrigin(text->getLocalBounds().getCenter());
}

void UI_Text::Render(RenderWindow* _window)
{
	_window->draw(*text);
}

void UI_Text::Destroy()
{
	font = nullptr;
	Super::Destroy();
}

string UI_Text::ToString()
{
	return Super::ToString() + ", Text: " + text->getString();
}