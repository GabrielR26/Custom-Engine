#pragma once

#include "Object.h"

/// <summary>
/// Basic rendered class in CustomEngine
/// </summary>
class RenderObject : public Object
{
	DECLARE_TYPE(RenderObject, Object)

protected:
	bool isRendered = true;

public:
	inline bool IsRendered() const { return isRendered; }
	inline virtual void SetIsRendered(const bool _value) { isRendered = _value; }

public:
	RenderObject(const bool _isRendered = true);

	/// <summary>
	/// Render the RenderObject
	/// </summary>
	/// <param name="_window"> RenderWindow to render </param>
	virtual void Render(RenderWindow* _window) = 0;

	// Inherited via Object
	virtual void Destroy() override;
};

