#pragma once

#include "SubSystem/SubSystem.h"
#include "Object/RenderObject.h"

#define LIST_RENDER_OBJECT_CAPACITY 100

/// <summary>
/// Subsystem to handle rendering
/// </summary>
class RenderSubSystem final : public SubSystem, public Singleton<RenderSubSystem>
{
	RenderWindow* mainWindow = nullptr;
	vector<RenderObject*> listRenderObject = vector<RenderObject*>();

public:
	RenderSubSystem() = default;
	~RenderSubSystem() = default;

	/// <summary>
	/// Render all listed renderObjects
	/// </summary>
	void Rendering();

	/// <summary>
	/// Add a renderObject for rendering
	/// </summary>
	/// <param name="_renderObject"> RenderObject to add </param>
	void AddRenderObject(RenderObject* _renderObject);
	/// <summary>
	/// Remove a RenderObject from rendering
	/// </summary>
	/// <param name="_renderObject"> RenderObject to remove </param>
	void RemoveRenderObject(RenderObject* _renderObject);

	// Inherited via SubSystem
	/// <summary>
	/// Initialize RenderSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown RenderSubSystem
	/// </summary>
	void Shutdown() override;
};

