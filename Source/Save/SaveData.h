#pragma once

#include "Base.h"

/// <summary>
/// Basic saved/loaded class in CustomEngine
/// </summary>
class SaveData : public Base
{
	DECLARE_TYPE(SaveData, Base)

	string path = "default";

public:
	inline string GetPath() const { return path; }

public:
	SaveData(const string& _path);

	/// <summary>
	/// Convert SaveData in JSon format
	/// </summary>
	/// <returns> A json data </returns>
	virtual json ToJson() = 0;
	/// <summary>
	/// Convert JSon data in SaveData format
	/// </summary>
	/// <param name="_json"> Json data to convert </param>
	virtual void FromJson(const json& _json) = 0;
};
