
#include "RenderObject.h"
#include "SubSystem/RenderSubSystem.h"

RenderObject::RenderObject(const bool _isRendered)
{
	isRendered = _isRendered;
	RenderSubSystem::Instance()->AddRenderObject(this);
}

void RenderObject::Destroy()
{
	RenderSubSystem::Instance()->RemoveRenderObject(this);
	Super::Destroy();
}
