#pragma once

#include "SubSystem.h"
#include "EngineEvent/EngineEvent.h"

/// <summary>
/// SubSystem to handle events (input, windows, ...)
/// </summary>
class EventSubSystem final : public SubSystem, public Singleton<EventSubSystem>
{
public:
	ENGINE_EVENT(windowFocusEvent, const bool)
	ENGINE_EVENT(textEnteredEvent, const char32_t)
	ENGINE_EVENT(keyPressedEvent, const Event::KeyPressed*)
	ENGINE_EVENT(keyReleasedEvent, const Event::KeyReleased*)
	ENGINE_EVENT(mouseWheelEvent, const Event::MouseWheelScrolled*)
	ENGINE_EVENT(mouseButtonPressedEvent, const Event::MouseButtonPressed*)
	ENGINE_EVENT(mouseButtonReleasedEvent, const Event::MouseButtonReleased*)
	ENGINE_EVENT(mouseMovedEvent, const Vector2i&)
	ENGINE_EVENT(mouseCapturedEvent, const bool)
	ENGINE_EVENT(joystickButtonPressedEvent, const Event::JoystickButtonPressed*)
	ENGINE_EVENT(joystickButtonReleasedEvent, const Event::JoystickButtonReleased*)
	ENGINE_EVENT(joystickMovedEvent, const Event::JoystickMoved*)
	ENGINE_EVENT(joystickConnectedEvent, const unsigned int, const bool)

private:
	RenderWindow* mainWindow = nullptr;
	bool lostFocus = false;

public:
	EventSubSystem() = default;
	~EventSubSystem() = default;

	/// <summary>
	/// Retrieve and process events
	/// </summary>
	void HandleEvents();

	// Inherited via SubSystem
	/// <summary>
	/// Initialize EventSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown EventSubSystem
	/// </summary>
	void Shutdown() override;
};