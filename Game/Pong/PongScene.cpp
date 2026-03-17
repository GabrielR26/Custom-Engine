
#include "PongScene.h"

PongScene::PongScene(const string& _name)
	: Scene(_name)
{
}

void PongScene::BuildingScene()
{
	pongManager = new PongManager();
}

void PongScene::ClearingScene()
{
	pongManager = nullptr;
}
