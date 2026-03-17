#pragma once

#include "UI.h"
#include "UI_Text.h"

#define DEFAULT_BUTTON_SIZE Vector2f(100.f, 50.f)
#define DEFAULT_BUTTON_COLOR Color::White
#define DEFAULT_BUTTON_TEXTURE nullptr

/// <summary>
/// Class to display a button (with optional text) for UI
/// </summary>
class UI_Button final : public UI
{
	DECLARE_TYPE(UI_Button, UI)

private:
	ENGINE_EVENT(onClicked)

	unique_ptr<RectangleShape> buttonShape = nullptr;
	UI_Text* buttonText = nullptr;

public:
	inline EEonClicked OnClicked() { return onClicked; }
	inline RectangleShape* GetButtonShape() { return buttonShape.get(); }
	inline UI_Text* GetButtonText() { return buttonText; }

	inline void SetIsRendered(const bool _value) override { isRendered = _value;  buttonText->SetIsRendered(_value); }
	inline void SetButtonShape(RectangleShape* _buttonShape) { buttonShape = make_unique<RectangleShape>(*_buttonShape);}
	inline void SetButtonText(UI_Text* _buttonText) { buttonText = _buttonText; buttonText->SetIsRendered(isRendered); }
	inline void SetPosition(const Vector2f& _position)
	{
		buttonShape->setPosition(_position);
		buttonText->GetText()->setPosition(_position);
	}
	inline void SetRotation(const float _degree)
	{
		buttonShape->setRotation(degrees(_degree));
		buttonText->GetText()->setRotation(degrees(_degree));
	}
	inline void SetScale(const Vector2f& _scale)
	{
		buttonShape->setScale(_scale);
		buttonText->GetText()->setScale(_scale);
	}
	inline void Move(const Vector2f& _offset)
	{
		buttonShape->move(_offset);
		buttonText->GetText()->move(_offset);
	}

public:
	UI_Button(const UI_Button& _other);
	UI_Button(RectangleShape* _buttonShape, const Vector2f& _position, const bool _isRendered = true);
	UI_Button(RectangleShape* _buttonShape, UI_Text* _buttonText, const Vector2f& _position, const bool _isRendered = true);

	UI_Button(const string& _string, const Vector2f& _position, const bool _isRendered = true);
	UI_Button(const string& _string, const Vector2f& _position, const Vector2f& _size, const bool _isRendered = true);
	UI_Button(const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Button(const string& _string, const Vector2f& _position, const Texture* _texture, const bool _isRendered = true);
	UI_Button(const string& _string, const Vector2f& _position, const Vector2f& _size, const Color& _color, const Texture* _texture, const bool _isRendered = true);

	UI_Button(UI_Text* _buttonText, const Vector2f& _position, const bool _isRendered = true);
	UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Vector2f& _size, const bool _isRendered = true);
	UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Color& _color, const bool _isRendered = true);
	UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Texture* _texture, const bool _isRendered = true);
	UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Vector2f& _size, const Color& _color, const Texture* _texture, const bool _isRendered = true);


	// Inherited via Object
	void Start() override;
	void Destroy() override;
	string ToString() override;

	// Inherited via UI
	void Render(RenderWindow* _window) override;

private:
	/// <summary>
	/// Function call when user click on button.
	/// Call every callback bind to onClicked event. 
	/// </summary>
	/// <param name="_sfEventMouseButtonPressed"> sf::Event of mouse button pressed </param>
	void MouseClicked(const Event::MouseButtonPressed* _sfEventMouseButtonPressed);

	// Inherited via UI
	void ResetOrigin() override;
};

