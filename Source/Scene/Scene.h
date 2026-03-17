#pragma once

#include "Base.h"

class Object;

#define LIST_SCENE_OBJECT_CAPACITY 200

/// <summary>
/// Class to store World's state (graph of objects)
/// </summary>
class Scene : public Base
{
	DECLARE_TYPE(Scene, Base)

private:
	string name = "Scene";
	bool isLoaded = true;
	vector<Object*> listSceneObject = vector<Object*>();

public:
	inline const string& GetName() const { return name; }
	inline bool IsLoaded() const { return isLoaded; }

public:
	Scene(const string& _name);

	/// <summary>
	/// Build all listed sceneObjects
	/// </summary>
	virtual void BuildingScene() = 0;
	/// <summary>
	/// Destroy all listed sceneObject
	/// </summary>
	virtual void ClearingScene() = 0;

	/// <summary>
	/// Load the Scene
	/// </summary>
	void Load();
	/// <summary>
	/// Unload the Scene
	/// </summary>
	void Unload();

	/// <summary>
	/// Add an object to the Scene
	/// </summary>
	/// <param name="_object"> Object to add </param>
	void AddObject(Object* _object);
	/// <summary>
	/// Add a list of objects to the Scene
	/// </summary>
	/// <param name="_listObject"> List of Object to add </param>
	void AddObjects(initializer_list<Object*> _listObject);
	/// <summary>
	/// Remove an object to the Scene
	/// </summary>
	/// <param name="_object"> Object to remove </param>
	void RemoveObject(Object* _object);
	/// <summary>
	/// Remove a list of objects to the Scene
	/// </summary>
	/// <param name="_listObject"> List of Object to remove </param>
	void RemoveObjects(initializer_list<Object*> _listObject);

	/// <summary>
	/// Destroy the Scene
	/// </summary>
	void Destroy();
};
