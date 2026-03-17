#include "TriggerBox.h"
#include "Actor/Actor.h"

TriggerBox::TriggerBox(const Vector2f& _position, const Vector2f& _size, const bool _isTrigger)
	: Object()
{
	isTrigger = _isTrigger;
	triggerZone = new FloatRect(_position - (_size * 0.5f), _size);
}

void TriggerBox::Update(const float _deltaTime)
{
	Super::Update(_deltaTime);

	if (!isTrigger)
		return;

	const size_t _listActorToTriggerSize = listActorToTrigger.size();
	for (size_t i = 0; i < _listActorToTriggerSize; i++)
	{
		Actor* _actor = listActorToTrigger[i]->actor;
		if (listActorToTrigger[i]->hasEnterTriggerZone == false && triggerZone->findIntersection(_actor->GetBoundingBox()))
		{
			listActorToTrigger[i]->hasEnterTriggerZone = true;
			onTriggerEnter->Invoke(_actor);
		}
		else if (listActorToTrigger[i]->hasEnterTriggerZone == true && !triggerZone->findIntersection(_actor->GetBoundingBox()))
		{
			listActorToTrigger[i]->hasEnterTriggerZone = false;
			onTriggerExit->Invoke(_actor);
		}
	}
}

void TriggerBox::AddActorToTrigger(Actor* _actor)
{
	THROW_IF_NULLPTR(_actor);

	listActorToTrigger.push_back(new ActorToTriggerData(_actor, false));
}

void TriggerBox::RemoveActorToTrigger(Actor* _actor)
{
	THROW_IF_NULLPTR(_actor);

	const size_t _listSize = listActorToTrigger.size();
	for (size_t i = 0; i < _listSize; i++)
	{
		if (listActorToTrigger[i]->actor == _actor)
		{
			listActorToTrigger.erase(listActorToTrigger.begin() + i);
			return;
		}
	}
}
