#pragma once

#include "Object/RenderObject.h"

/// <summary>
/// Basic rendered class for UI elements in CustomEngine
/// </summary>
class UI : public RenderObject
{
	DECLARE_TYPE(UI, RenderObject)

public:
	UI(const bool _isRendered = true);

	// Inherited via RenderObject
	virtual void Render(RenderWindow* _window) override = 0;

protected:
	/// <summary>
	/// Reset origin to the center
	/// </summary>
	virtual void ResetOrigin() = 0;
};
