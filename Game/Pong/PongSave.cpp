#include "PongSave.h"

PongSave::PongSave()
	: SaveData("pong_save")
{
	player1Score = 0;
	player2Score = 0;
}

void PongSave::UpdateSave(const int _player1Score, const int _player2Score)
{
	player1Score = _player1Score;
	player2Score = _player2Score;
}

json PongSave::ToJson()
{
	return json{
		{ "player1Score", player1Score},
		{ "player2Score", player2Score}
	};
}

void PongSave::FromJson(const json& _json)
{
	if (_json.contains("player1Score"))
		_json.at("player1Score").get_to(player1Score);
	if (_json.contains("player2Score"))
		_json.at("player2Score").get_to(player2Score);
}
