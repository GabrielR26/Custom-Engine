
#include "EventSubSystem.h"

void EventSubSystem::Initialize()
{
	LOG("Initialization", "EventSubSystem", terminal_color::bright_cyan);

	mainWindow = Engine::GetMainWindow();
}

void EventSubSystem::Shutdown()
{
	LOG("Shutting down", "EventSubSystem", terminal_color::bright_cyan);

	windowFocusEvent->RemoveAllListeners();
	textEnteredEvent->RemoveAllListeners();
	keyPressedEvent->RemoveAllListeners();
	keyReleasedEvent->RemoveAllListeners();
	mouseWheelEvent->RemoveAllListeners();
	mouseButtonPressedEvent->RemoveAllListeners();
	mouseButtonReleasedEvent->RemoveAllListeners();
	mouseMovedEvent->RemoveAllListeners();
	mouseCapturedEvent->RemoveAllListeners();
	joystickButtonPressedEvent->RemoveAllListeners();
	joystickButtonReleasedEvent->RemoveAllListeners();
	joystickMovedEvent->RemoveAllListeners();
	joystickConnectedEvent->RemoveAllListeners();

	DestroyInstance();
}

void EventSubSystem::HandleEvents()
{
	while (optional<Event> _sfEvent = mainWindow->pollEvent())
	{
		// Window closed
		if (_sfEvent->is<Event::Closed>())
			Engine::Closing();

		// Window focus gained/lost
		if (_sfEvent->getIf<Event::FocusLost>())
		{
			windowFocusEvent->Invoke(false);
			lostFocus = true;
		}
		else if (_sfEvent->getIf<Event::FocusGained>())
		{
			windowFocusEvent->Invoke(true);
			lostFocus = false;
		}

		if (lostFocus)
			return;

		// Text entered
		if (const Event::TextEntered* _sfEventTextEntered = _sfEvent->getIf<Event::TextEntered>())
		{
			textEnteredEvent->Invoke(_sfEventTextEntered->unicode);
		}

		// Key pressed/released
		if (const Event::KeyPressed* _sfEventKeyPressed = _sfEvent->getIf<Event::KeyPressed>())
		{
			keyPressedEvent->Invoke(_sfEventKeyPressed);
		}
		else if (const Event::KeyReleased* _sfEventKeyReleased = _sfEvent->getIf<Event::KeyReleased>())
		{
			keyReleasedEvent->Invoke(_sfEventKeyReleased);
		}

#pragma region Mouse
		// Mouse wheel scrolled
		if (const Event::MouseWheelScrolled* _sfEventMouseWheelScrolled = _sfEvent->getIf<Event::MouseWheelScrolled>())
		{
			mouseWheelEvent->Invoke(_sfEventMouseWheelScrolled);
		}

		// Mouse button pressed/released
		if (const Event::MouseButtonPressed* _sfEventMouseButtonPressed = _sfEvent->getIf<Event::MouseButtonPressed>())
		{
			mouseButtonPressedEvent->Invoke(_sfEventMouseButtonPressed);
		}
		else if (const Event::MouseButtonReleased* _sfEventMouseButtonReleased = _sfEvent->getIf<Event::MouseButtonReleased>())
		{
			mouseButtonReleasedEvent->Invoke(_sfEventMouseButtonReleased);
		}

		// Mouse moved
		if (const Event::MouseMoved* _sfEventMouseMoved = _sfEvent->getIf<Event::MouseMoved>())
		{
			mouseMovedEvent->Invoke(_sfEventMouseMoved->position);
		}

		// Mouse captured
		if (_sfEvent->getIf<Event::MouseEntered>())
		{
			mouseCapturedEvent->Invoke(true);
		}
		else if (_sfEvent->getIf<Event::MouseLeft>())
		{
			mouseCapturedEvent->Invoke(false);
		}
#pragma endregion

#pragma region Joystick
		// Joystick button pressed/released
		if (const Event::JoystickButtonPressed* _sfEventJoystickButtonPressed = _sfEvent->getIf<Event::JoystickButtonPressed>())
		{
			joystickButtonPressedEvent->Invoke(_sfEventJoystickButtonPressed);
		}
		else if (const Event::JoystickButtonReleased* _sfEventJoystickButtonReleased = _sfEvent->getIf<Event::JoystickButtonReleased>())
		{
			joystickButtonReleasedEvent->Invoke(_sfEventJoystickButtonReleased);
		}

		// Joystick moved
		if (const Event::JoystickMoved* _sfEventJoystickMoved = _sfEvent->getIf<Event::JoystickMoved>())
		{
			joystickMovedEvent->Invoke(_sfEventJoystickMoved);
		}

		// Joystick connected
		if (const Event::JoystickConnected* _sfEventJoystickConnected = _sfEvent->getIf<Event::JoystickConnected>())
		{
			joystickConnectedEvent->Invoke(_sfEventJoystickConnected->joystickId, true);
		}
		else if (const Event::JoystickDisconnected* _sfEventJoystickDisconnected = _sfEvent->getIf<Event::JoystickDisconnected>())
		{
			joystickConnectedEvent->Invoke(_sfEventJoystickDisconnected->joystickId, false);
		}
#pragma endregion
	}
}
