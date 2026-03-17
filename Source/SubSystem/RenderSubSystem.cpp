
#include "RenderSubSystem.h"

void RenderSubSystem::Rendering()
{
	const size_t _listRenderObjectSize = listRenderObject.size();
#pragma omp parallel for
	for (size_t i = 0; i < _listRenderObjectSize; i++)
	{
		RenderObject* _renderObject = listRenderObject[i];
		if (_renderObject->IsRendered() && _renderObject->IsEnabled())
			_renderObject->Render(mainWindow);
	}
}

void RenderSubSystem::AddRenderObject(RenderObject* _renderObject)
{
	THROW_IF_NULLPTR(_renderObject);

	listRenderObject.push_back(_renderObject);
}

void RenderSubSystem::RemoveRenderObject(RenderObject* _renderObject)
{
	THROW_IF_NULLPTR(_renderObject);

	vector<RenderObject*>::const_iterator _it = find(listRenderObject.begin(), listRenderObject.end(), _renderObject);
	if (_it != listRenderObject.end())
		listRenderObject.erase(_it);
}

void RenderSubSystem::Initialize()
{
	LOG("Initialization", "RenderSubSystem", terminal_color::bright_cyan);

	mainWindow = Engine::GetMainWindow();
	listRenderObject.reserve(LIST_RENDER_OBJECT_CAPACITY);
}

void RenderSubSystem::Shutdown()
{
	const size_t _listRenderObjectSize = listRenderObject.size();
	for (size_t i = 0; i < _listRenderObjectSize; i++)
		listRenderObject[i] = nullptr;
	listRenderObject.clear();

	LOG("Shutting down", "RenderSubSystem", terminal_color::bright_cyan);
	DestroyInstance();
}
