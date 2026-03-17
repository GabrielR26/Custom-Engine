
#include "PongManager.h"

void PongManager::Start()
{
	Super::Start();

	const Vector2u _windowSize = Engine::GetMainWindowSize();

	// Resources
	font = ResourceSubSystem::Instance()->LoadFont("pixel.ttf");
	texture = ResourceSubSystem::Instance()->LoadTexture("Pong_Title.png");
	music = ResourceSubSystem::Instance()->LoadMusic("Tetris theme.mp3");
	music->setVolume(1.f);
	soundBufferScored = ResourceSubSystem::Instance()->LoadSound("Pong-sound.wav");
	soundScored = new Sound(*soundBufferScored);
	soundScored->setPitch(0.5f);

	// Game
	topBound = new Actor(new RectangleShape(Vector2f(_windowSize.x, 1.f)), { _windowSize.x * 0.5f, -1.f });
	bottomBound = new Actor(new RectangleShape(Vector2f(_windowSize.x, 1.f)), { _windowSize.x * 0.5f, _windowSize.y + 1.f });
	leftBar = new Bar(this, true);
	rightBar = new Bar(this, false);
	ball = new Ball(this);

	leftTrigger = new TriggerBox(Vector2f(-5.f, _windowSize.y * 0.5f), Vector2f(1.f, _windowSize.y));
	leftTrigger->AddActorToTrigger(ball);
	leftTrigger->OnTriggerEnter()->AddListener(this, &PongManager::UpdateScorePlayer2);
	rightTrigger = new TriggerBox(Vector2f(_windowSize.x + 5.f, _windowSize.y * 0.5f), Vector2f(1.f, _windowSize.y));
	rightTrigger->AddActorToTrigger(ball);
	rightTrigger->OnTriggerEnter()->AddListener(this, &PongManager::UpdateScorePlayer1);

	save = new PongSave();
	if (SaveSubSystem::Instance()->Load(*save))
	{
		player1Score = save->GetPlayer1Score();
		player2Score = save->GetPlayer2Score();
	}
	else
	{
		player1Score = 0;
		player2Score = 0;
	}

	// UI
	txt_Player1 = new UI_Text(font, "PLAYER 1", Vector2f(_windowSize.x * 0.45f, 25.f), Color(255, 255, 255, 100), 15);
	txt_Player2 = new UI_Text(font, "PLAYER 2", Vector2f(_windowSize.x * 0.55f, 25.f), Color(255, 255, 255, 100), 15);
	txt_Player1Score = new UI_Text(font, to_string(player1Score), Vector2f(_windowSize.x * 0.45f, 50.f), Color(255, 255, 255, 100));
	txt_Player2Score = new UI_Text(font, to_string(player2Score), Vector2f(_windowSize.x * 0.55f, 50.f), Color(255, 255, 255, 100));
	btn_Start = new UI_Button("START", Vector2f(_windowSize.x * 0.5f, _windowSize.y * 0.80f), { 150, 50 });
	btn_Start->GetButtonText()->SetColor(Color::Black);
	img_title = new UI_Image(texture, Vector2f(_windowSize.x * 0.5f, _windowSize.y * 0.5f), { 2, 2 });
	btn_Start->OnClicked()->AddListener(this, &PongManager::StartGame);
}

void PongManager::Destroy()
{
	save->UpdateSave(player1Score, player2Score);
	SaveSubSystem::Instance()->Save(save);

	font = nullptr;
	texture = nullptr;
	music = nullptr;
	soundBufferScored = nullptr;
	soundScored = nullptr;
	ball = nullptr;
	leftBar = nullptr;
	rightBar = nullptr;
	leftTrigger = nullptr;
	rightTrigger = nullptr;
	save = nullptr;
	btn_Start = nullptr;
	img_title = nullptr;
	txt_Player1 = nullptr;
	txt_Player2 = nullptr;
	txt_Player1Score = nullptr;
	txt_Player2Score = nullptr;

	Super::Destroy();
}

void PongManager::StartGame()
{
	music->play();
	btn_Start->SetIsRendered(false);
	img_title->SetIsRendered(false);

	onGameStart->Invoke();
	ball->Launch();
}

void PongManager::UpdateScorePlayer1(Actor* _ball)
{
	player1Score++;
	txt_Player1Score->SetText(to_string(player1Score));
	PlayerScored();
}

void PongManager::UpdateScorePlayer2(Actor* _ball)
{
	player2Score++;
	txt_Player2Score->SetText(to_string(player2Score));
	PlayerScored();
}

void PongManager::PlayerScored()
{
	soundScored->play();
	ball->Reset();
	StartTimer(1.0f, [=]()
		{
			ball->Launch();
		});
}