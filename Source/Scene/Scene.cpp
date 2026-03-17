#include "Scene.h"
#include "SubSystem/SceneSubSystem.h"
#include "Object/Object.h"

Scene::Scene(const string& _name)
{
	name = _name;
	isLoaded = false;
	listSceneObject.reserve(LIST_SCENE_OBJECT_CAPACITY);
	SceneSubSystem::Instance()->AddScene(this);
}

void Scene::Load()
{
	LOG("Loading " + name, "SCENE", terminal_color::green);

	BuildingScene();
	isLoaded = true;
}

void Scene::Unload()
{
	LOG("Unloading " + name, "SCENE", terminal_color::yellow);

	const size_t _listSceneObjectSize = listSceneObject.size();
	for (size_t i = 0; i < _listSceneObjectSize; i++)
	{
		listSceneObject[i]->Destroy();
		listSceneObject[i] = nullptr;
	}
	listSceneObject.clear();

	isLoaded = false;
	ClearingScene();
}

void Scene::AddObject(Object* _object)
{
	THROW_IF_NULLPTR(_object);

	listSceneObject.push_back(_object);
}

void Scene::AddObjects(initializer_list<Object*> _listObject)
{
	THROW_ERROR("_listObject is empty");

	for (Object* _object : _listObject)
		AddObject(_object);
}

void Scene::RemoveObject(Object* _object)
{
	THROW_IF_NULLPTR(_object);

	vector<Object*>::const_iterator _it = find(listSceneObject.begin(), listSceneObject.end(), _object);
	if (_it != listSceneObject.end())
		listSceneObject.erase(_it);
}

void Scene::RemoveObjects(initializer_list<Object*> _listObject)
{
	THROW_ERROR("_listObject is empty");

	for (Object* _object : _listObject)
		RemoveObject(_object);
}

void Scene::Destroy()
{
	// Objects already deleted in GameSubSystem

	const size_t _listSceneObjectSize = listSceneObject.size();
	for (size_t i = 0; i < _listSceneObjectSize; i++)
		listSceneObject[i] = nullptr;
	listSceneObject.clear();
}
