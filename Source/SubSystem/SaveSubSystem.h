#pragma once

#include "SubSystem.h"
#include "Save/SaveData.h"

#define SAVE_FOLDER "Save/"
#define SAVE_EXTENSION ".json"

/// <summary>
/// SubSystem to manage data save/load
/// </summary>
class SaveSubSystem : public SubSystem, public Singleton<SaveSubSystem>
{
public:
	SaveSubSystem() = default;
	~SaveSubSystem() = default;

	/// <summary>
	/// Save a SaveData in JSon format
	/// </summary>
	/// <param name="_saveData"> SaveData to save </param>
	/// <returns> True if successfully save, false otherwise </returns>
	bool Save(SaveData* _saveData);
	/// <summary>
	/// Load a Json file (on SaveData's path) in SaveData format
	/// </summary>
	/// <param name="_saveData"> SaveData where load data </param>
	/// <returns> True if successfully load, false otherwise </returns>
	bool Load(SaveData& _saveData);

	// Inherited via SubSystem
	/// <summary>
	/// Initialize SaveSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown SaveSubSystem
	/// </summary>
	void Shutdown() override;
};

