
#include "GameSubSystem.h"
#include "Object/Object.h"

void GameSubSystem::Updating(const float _deltaTime)
{
	/// Update objects
	const size_t _listObjectSize = listObject.size();
	for (size_t i = 0; i < _listObjectSize; i++)
	{
		Object* _object = listObject[i];
		if (_object->IsEnabled() && !_object->IsPendingDestroy())
		{
			if (_object->IsFirstUpdate())
			{
				_object->Start();
				_object->HasFirstUpdate();
			}
			else
				_object->Update(_deltaTime);
		}
	}

	/// Update timers
	const int _listTimerSize = listTimer.size() - 1;
	for (int i = _listTimerSize; i >= 0; i--)
	{
		listTimer[i].duration -= _deltaTime;

		if (listTimer[i].duration <= 0.f)
		{
			listTimer[i].callback();
			listTimer.erase(listTimer.begin() + i);
		}
	}

	DeletePendingDestroyObjects();
}

void GameSubSystem::AddObject(Object* _object)
{
	THROW_IF_NULLPTR(_object);

	listObject.push_back(_object);

	LOG("Add new Object " + to_string(_object->GetID()), "GameSubSystem", terminal_color::green);
}

void GameSubSystem::AddTimer(const float _time, function<void()> _callback)
{
	THROW_IF_NULLPTR(_callback);
	if (_time <= 0.f)
		THROW_ERROR("_time must be greater than zero");

	listTimer.push_back({ _time, _callback });
}

void GameSubSystem::DeletePendingDestroyObjects()
{
	for (vector<Object*>::iterator it = listObject.begin(); it != listObject.end(); )
	{
		Object* _obj = *it;
		if (_obj && _obj->IsPendingDestroy())
		{
			delete _obj;
			it = listObject.erase(it);
		}
		else
			++it;
	}
}

void GameSubSystem::Initialize()
{
	LOG("Initialization", "GameSubSystem", terminal_color::bright_cyan);
	listObject.reserve(LIST_OBJECT_CAPACITY);
}

void GameSubSystem::Shutdown()
{
	const size_t _listObjectSize = listObject.size();
	for (size_t i = 0; i < _listObjectSize; i++)
	{
		delete listObject[i];
		listObject[i] = nullptr;
	}
	listObject.clear();

	listTimer.clear();

	LOG("Shutting down", "GameSubSystem", terminal_color::bright_cyan);
	DestroyInstance();
}
