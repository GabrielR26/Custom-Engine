
#include "UI_Button.h"
#include "SubSystem/EventSubSystem.h"

UI_Button::UI_Button(const UI_Button& _other)
{
	buttonShape = make_unique<RectangleShape>(*_other.buttonShape);
	buttonText = _other.buttonText;
	isRendered = _other.isRendered;
}

UI_Button::UI_Button(RectangleShape* _buttonShape, const Vector2f& _position, const bool _isRendered)
	: UI_Button(_buttonShape, nullptr, _position, _isRendered)
{
}

UI_Button::UI_Button(RectangleShape* _buttonShape, UI_Text* _buttonText, const Vector2f& _position, const bool _isRendered)
	: UI(_isRendered)
{
	buttonShape = _buttonShape ? make_unique<RectangleShape>(*_buttonShape) : make_unique<RectangleShape>(DEFAULT_BUTTON_SIZE);

	if (_buttonText)
	{
		buttonText = _buttonText;
		buttonText->SetIsRendered(_isRendered);
	}
	else
		buttonText = new UI_Text(DEFAULT_TEXT, _isRendered);

	ResetOrigin();
	buttonShape->setPosition(_position);
	buttonText->GetText()->setPosition(_position);
}

UI_Button::UI_Button(const string& _string, const Vector2f& _position, const bool _isRendered)
	: UI_Button(_string, _position, DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_COLOR, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(const string& _string, const Vector2f& _position, const Vector2f& _size, const bool _isRendered)
	: UI_Button(_string, _position, _size, DEFAULT_BUTTON_COLOR, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(const string& _string, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Button(_string, _position, DEFAULT_BUTTON_SIZE, _color, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(const string& _string, const Vector2f& _position, const Texture* _texture, const bool _isRendered)
	: UI_Button(_string, _position, DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_COLOR, _texture, _isRendered)
{
}

UI_Button::UI_Button(const string& _string, const Vector2f& _position, const Vector2f& _size, const Color& _color, const Texture* _texture, const bool _isRendered)
	: UI(_isRendered)
{
	buttonShape = make_unique<RectangleShape>(_size);
	buttonShape->setTexture(_texture);
	buttonShape->setFillColor(_color);

	buttonText = new UI_Text(_string);
	buttonText->SetIsRendered(_isRendered);

	ResetOrigin();
	buttonShape->setPosition(_position);
	buttonText->GetText()->setPosition(_position);
}

UI_Button::UI_Button(UI_Text* _buttonText, const Vector2f& _position, const bool _isRendered)
	: UI_Button(_buttonText, _position, DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_COLOR, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Vector2f& _size, const bool _isRendered)
	: UI_Button(_buttonText, _position, _size, DEFAULT_BUTTON_COLOR, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Color& _color, const bool _isRendered)
	: UI_Button(_buttonText, _position, DEFAULT_BUTTON_SIZE, _color, DEFAULT_BUTTON_TEXTURE, _isRendered)
{
}

UI_Button::UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Texture* _texture, const bool _isRendered)
	: UI_Button(_buttonText, _position, DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_COLOR, _texture, _isRendered)
{
}

UI_Button::UI_Button(UI_Text* _buttonText, const Vector2f& _position, const Vector2f& _size, const Color& _color, const Texture* _texture, const bool _isRendered)
	: UI(_isRendered)
{
	buttonShape = make_unique<RectangleShape>(_size);
	buttonShape->setTexture(_texture);
	buttonShape->setFillColor(_color);

	if (_buttonText)
	{
		buttonText = _buttonText;
		buttonText->SetIsRendered(_isRendered);
	}
	else
		buttonText = new UI_Text(DEFAULT_TEXT, _isRendered);

	ResetOrigin();
	buttonShape->setPosition(_position);
	buttonText->GetText()->setPosition(_position);
}

void UI_Button::Render(RenderWindow* _window)
{
	_window->draw(*buttonShape);
	// Text rendering itself
}

void UI_Button::Start()
{
	Super::Start();
	EventSubSystem::Instance()->mouseButtonPressedEvent->AddListener(this, &UI_Button::MouseClicked);
}

void UI_Button::ResetOrigin()
{
	buttonShape->setOrigin(buttonShape->getLocalBounds().getCenter());
}

void UI_Button::MouseClicked(const Event::MouseButtonPressed* _sfEventMouseButtonPressed)
{
	if (!isRendered)
		return;

	if (_sfEventMouseButtonPressed->button == Mouse::Button::Left)
	{
		const Vector2f& _mousePos = Vector2f(_sfEventMouseButtonPressed->position);
		if (buttonShape->getGlobalBounds().contains(_mousePos))
			onClicked->Invoke();
	}
}

void UI_Button::Destroy()
{
	onClicked->RemoveAllListeners();
	buttonText = nullptr;
	Super::Destroy();
}

string UI_Button::ToString()
{
	return Super::ToString() + ", Text: " + buttonText->GetString();
}
