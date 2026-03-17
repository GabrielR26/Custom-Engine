#pragma once

#include "SubSystem/SubSystem.h"

#define LIST_OBJECT_CAPACITY 1000

class Object;

/// <summary>
/// Time and callback wrapper for event timer in CustomEngine
/// </summary>
struct Timer
{
	float duration;
	function<void()> callback;
};

/// <summary>
/// Subsystem to handle objects's update and timers
/// </summary>
class GameSubSystem final : public SubSystem, public Singleton<GameSubSystem>
{
	vector<Object*> listObject = vector<Object*>();
	vector<Timer> listTimer = vector<Timer>();

public:
	GameSubSystem() = default;
	~GameSubSystem() = default;

	/// <summary>
	/// Update all listed Objects and remaining timers
	/// </summary>
	/// <param name="_deltaTime"> Delta time of current engine frame </param> 
	void Updating(const float _deltaTime);

	/// <summary>
	/// Add an Object for updating
	/// </summary>
	/// <param name="_object"> Object to add </param>
	void AddObject(Object* _object);
	/// <summary>
	/// Add a Timer
	/// </summary>
	/// <param name="_time"> Time of Timer </param>
	/// <param name="_callback"> Function call at timer's end </param>
	void AddTimer(const float _time, function<void()> _callback);

	// Inherited via SubSystem	
	/// <summary>
	/// Initialize GameSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown GameSubSystem
	/// </summary>
	void Shutdown() override;

private:
	/// <summary>
	/// Delete all listed objects marked pending destroy
	/// </summary>
	void DeletePendingDestroyObjects();
};

