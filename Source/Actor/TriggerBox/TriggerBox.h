#pragma once

#include "Object/Object.h"

class Actor;

/// <summary>
/// Wrapper for triggered Actor
/// </summary>
struct ActorToTriggerData
{
	Actor* actor = nullptr;
	bool hasEnterTriggerZone = false;
};

/// <summary>
/// Class to detect Actor entering/exiting a zone
/// </summary>
class TriggerBox final : public Object
{
	DECLARE_TYPE(TriggerBox, Object)

private:
	ENGINE_EVENT(onTriggerEnter, Actor*)
	ENGINE_EVENT(onTriggerExit, Actor*)

	bool isTrigger = true;
	FloatRect* triggerZone = nullptr;
	vector<ActorToTriggerData*> listActorToTrigger;

public:
	inline EEonTriggerEnter OnTriggerEnter() { return onTriggerEnter; }
	inline EEonTriggerExit OnTriggerExit() { return onTriggerExit; }
	inline bool IsTrigger() const { return isTrigger; }
	inline void SetIsTrigger(const bool _value) { isTrigger = _value; }

public:
	TriggerBox(const Vector2f& _position, const Vector2f& _size, const bool _isTrigger = true);

	/// <summary>
	/// Add an Actor for detection
	/// </summary>
	/// <param name="_actor"> Actor to add </param>
	void AddActorToTrigger(Actor* _actor);
	/// <summary>
	/// Remove an Actor for detection
	/// </summary>
	/// <param name="_actor"> Actor to remove </param>
	void RemoveActorToTrigger(Actor* _actor);

	// Inherited via Object
	void Update(const float _deltaTime) override;
};

