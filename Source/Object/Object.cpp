
#include "Object.h"
#include "SubSystem/GameSubSystem.h"
#include "SubSystem/SceneSubSystem.h"

Object::Object()
{
	id = GenerateObjectID();
	firstUpdate = true;
	GameSubSystem::Instance()->AddObject(this);
	SceneSubSystem::Instance()->GetCurrentScene()->AddObject(this);
}

void Object::Start()
{
}

void Object::Update(const float _deltaTime)
{
	if (!isEnabled)
		return;
}

void Object::Destroy()
{
	isPendingDestroy = true;
	LOG("Object " + to_string(id) + " is pending destroy", "OBJECT", terminal_color::yellow);
}

void Object::StartTimer(float _time, function<void()> _callback)
{
	GameSubSystem::Instance()->AddTimer(_time, _callback);
}

string Object::ToString()
{
	return GetTypeInfo()->name + " " + to_string(id);
}
