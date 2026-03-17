#pragma once

#include "Save/SaveData.h"

class PongSave : public SaveData
{
	int player1Score = 0;
	int player2Score = 0;

public:
	inline int GetPlayer1Score() const { return player1Score; }
	inline int GetPlayer2Score() const { return player2Score; }

public:
	PongSave();

	void UpdateSave(const int _player1Score, const int _player2Score);

	// Inherited via SaveData
	json ToJson() override;
	void FromJson(const json& _json) override;
};

