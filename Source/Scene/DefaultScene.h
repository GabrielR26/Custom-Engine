#pragma once

#include "Scene.h"
#include "UI/UI_Text.h"

/// <summary>
/// Default Scene for CustomEngine
/// </summary>
class DefaultScene final : public Scene
{
	UI_Text* defaultObject = nullptr;

public:
	DefaultScene(const string& _name);

	// Inherited via Scene
	void BuildingScene() override;
	void ClearingScene() override;
};

