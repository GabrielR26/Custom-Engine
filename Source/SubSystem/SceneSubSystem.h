#pragma once

#include "SubSystem.h"
#include "Scene/Scene.h"

/// <summary>
/// SubSystem to manage scene
/// </summary>
class SceneSubSystem final : public SubSystem, public Singleton<SceneSubSystem>
{
protected:
	vector<Scene*> listScene = vector<Scene*>();
	Scene* currentScene = nullptr;

public:
	inline Scene* GetCurrentScene() const { return currentScene; }

public:
	SceneSubSystem() = default;
	~SceneSubSystem() = default;

	/// <summary>
	/// Add a scene to manage
	/// </summary>
	/// <param name="_scene"> Scene to add </param>
	void AddScene(Scene* _scene);
	/// <summary>
	/// Change the current Scene to another
	/// </summary>
	/// <param name="_sceneName"> Scene's name to load </param>
	void ChangeScene(const string& _sceneName);

	// Inherited via SubSystem
	/// <summary>
	/// Initialize SceneSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown SceneSubSystem
	/// </summary>
	void Shutdown() override;
};

