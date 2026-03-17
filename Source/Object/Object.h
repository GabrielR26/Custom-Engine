#pragma once

#include "Base.h"
#include "Engine/Engine.h"
#include "EngineEvent/EngineEvent.h"
#include "SubSystem/ResourceSubSystem.h"
#include "SubSystem/SaveSubSystem.h"

using ObjectId = uint64_t;
/// <summary>
/// Generate an ObjectId for each Object
/// </summary>
/// <returns> Object's id </returns>
inline ObjectId GenerateObjectID()
{
	// Warning : not thread-safe
	static ObjectId _lastId = 0;
	return _lastId++;
}

/// <summary>
/// Basic manipulated class by user in CustomEngine
/// </summary>
class Object : public Base
{
	DECLARE_TYPE(Object, Base)

private:
	ObjectId id = 0;
	bool firstUpdate = true;

public:
	inline ObjectId GetID() const { return id; }
	inline bool IsFirstUpdate() const { return firstUpdate; }
	inline void HasFirstUpdate() { firstUpdate = false; }

public:
	Object();

	/// <summary>
	/// First method called at runtime
	/// </summary>
	virtual void Start();
	/// <summary>
	/// Call every update at runtime
	/// </summary>
	/// <param name="_deltaTime"> Time between engine's frame</param>
	virtual void Update(const float _deltaTime);
	/// <summary>
	/// Last method called at runtime 
	/// </summary>
	virtual void Destroy();

	/// <summary>
	/// Start a new timer handle by GameSubSystem
	/// </summary>
	/// <param name="_duration"> Timer's duration </param>
	/// <param name="_callback"> Function to call back at Timer's end </param>
	void StartTimer(float _duration, function<void()> _callback);

	/// <summary>
	/// Return Object on string format 
	/// </summary>
	/// <returns> Object's string </returns>
	virtual string ToString();
};