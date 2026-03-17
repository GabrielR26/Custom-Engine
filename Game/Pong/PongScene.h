#pragma once

#include "Scene/Scene.h"
#include "UI/UI_Button.h"
#include "UI/UI_Image.h"
#include "UI/UI_Text.h"
#include "Ball.h"
#include "Bar.h"
#include "PongManager.h"

class PongScene : public Scene
{
	PongManager* pongManager = nullptr;

public:
	PongScene(const string& _name);

	// Inherited via Scene
	void BuildingScene() override;
	void ClearingScene() override;
};

