
#include "SceneSubSystem.h"
#include "Scene/DefaultScene.h"

void SceneSubSystem::AddScene(Scene* _scene)
{
	THROW_IF_NULLPTR(_scene);
	listScene.push_back(_scene);
}

void SceneSubSystem::ChangeScene(const string& _sceneName)
{
	const size_t _listSceneSize = listScene.size();
	Scene* _newScene = nullptr;
	for (size_t i = 0; i < _listSceneSize; i++)
	{
		if (listScene[i]->GetName() == _sceneName)
		{
			currentScene->Unload();
			currentScene = listScene[i];
			currentScene->Load();
			return;
		}
	}

	THROW_ERROR(format("No scene with name '{}' found", _sceneName));
}

void SceneSubSystem::Initialize()
{
	LOG("Initialization", "SceneSubSystem", terminal_color::bright_cyan);

	currentScene = new DefaultScene("DefaultScene");
	currentScene->Load();
}

void SceneSubSystem::Shutdown()
{
	currentScene->Unload();
	currentScene = nullptr;

	const size_t _listSceneSize = listScene.size();
	for (size_t i = 0; i < _listSceneSize; i++)
	{
		delete listScene[i];
		listScene[i] = nullptr;
	}
	listScene.clear();

	LOG("Shutting down", "SceneSubSystem", terminal_color::bright_cyan);
	DestroyInstance();
}
