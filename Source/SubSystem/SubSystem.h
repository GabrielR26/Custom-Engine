#pragma once

#include "Utils/Singleton.h"
#include "Engine/Engine.h"

/// <summary>
/// Base class for all SubSystems in the engine
/// </summary>
class SubSystem
{
public:
	SubSystem() = default;
	virtual ~SubSystem() = default;

	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;
};
