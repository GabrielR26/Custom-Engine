#include "DefaultScene.h"

DefaultScene::DefaultScene(const string& _name)
	: Scene(_name)
{
}

void DefaultScene::BuildingScene()
{
	defaultObject = new UI_Text("DEFAULT_SCENE");
}

void DefaultScene::ClearingScene()
{
	defaultObject = nullptr;
}
