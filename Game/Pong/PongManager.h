#pragma once

#include "Object/Object.h"
#include "UI/UI_Button.h"
#include "UI/UI_Image.h"
#include "UI/UI_Text.h"
#include "Ball.h"
#include "Bar.h"
#include "PongSave.h"

class PongManager : public Object
{
	DECLARE_TYPE(PongManager, Object)

	ENGINE_EVENT(onGameStart)

	Font* font = nullptr;
	Texture* texture = nullptr;
	Music* music = nullptr;
	SoundBuffer* soundBufferScored = nullptr;
	Sound* soundScored = nullptr;

	Ball* ball = nullptr;
	Bar* leftBar = nullptr;
	Bar* rightBar = nullptr;
	TriggerBox* leftTrigger = nullptr;
	TriggerBox* rightTrigger = nullptr;
	Actor* topBound = nullptr;
	Actor* bottomBound = nullptr;
	PongSave* save = nullptr;

	UI_Button* btn_Start = nullptr;
	UI_Image* img_title = nullptr;
	UI_Text* txt_Player1 = nullptr;
	UI_Text* txt_Player2 = nullptr;
	UI_Text* txt_Player1Score = nullptr;
	UI_Text* txt_Player2Score = nullptr;

	unsigned int player1Score = 0;
	unsigned int player2Score = 0;

public:
	inline EEonGameStart OnGameStart() { return onGameStart; }
	inline Bar* GetLeftBar() const { return leftBar; }
	inline Bar* GetRightBar() const { return rightBar; }
	inline Actor* GetTopBound() const { return topBound; }
	inline Actor* GetBottomBound() const { return bottomBound; }

public:
	PongManager() = default;

	void Start() override;
	void Destroy() override;

	void StartGame();
	void UpdateScorePlayer1(Actor* _ball);
	void UpdateScorePlayer2(Actor* _ball);
	void PlayerScored();
};