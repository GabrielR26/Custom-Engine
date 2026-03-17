
#include "SaveSubSystem.h"

bool SaveSubSystem::Save(SaveData* _saveData)
{
	filesystem::path _saveDataFullPath = SAVE_FOLDER + (_saveData->GetPath() + SAVE_EXTENSION);

	ofstream _saveFile = ofstream(_saveDataFullPath);
	_saveFile << _saveData->ToJson().dump();

	return true;
}

bool SaveSubSystem::Load(SaveData& _saveData)
{
	path _saveDataFullPath = SAVE_FOLDER + (_saveData.GetPath() + SAVE_EXTENSION);

	if (!exists(_saveDataFullPath))
		return false;

	ifstream _saveFile = ifstream(_saveDataFullPath);
	json _saveJson;
	_saveFile >> _saveJson;
	_saveData.FromJson(_saveJson);

	return true;
}

void SaveSubSystem::Initialize()
{
	LOG("Initialization", "SaveSubSystem", terminal_color::bright_cyan);
}

void SaveSubSystem::Shutdown()
{
	LOG("Shutting down", "SaveSubSystem", terminal_color::bright_cyan);
	DestroyInstance();
}
