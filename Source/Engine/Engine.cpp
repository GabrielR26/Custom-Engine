
#include "Engine.h"
#include "SubSystem/GameSubSystem.h"
#include "SubSystem/RenderSubSystem.h"
#include "SubSystem/EventSubSystem.h"
#include "SubSystem/ResourceSubSystem.h"
#include "SubSystem/SceneSubSystem.h"
#include "SubSystem/SaveSubSystem.h"

#include "../Game/Pong/PongScene.h"

void Engine::Initialization()
{
	LOG("Engine Starting...", "ENGINE", terminal_color::cyan);

	// Window
	InitializeWindow();

	// Initialize SubSystems
	GameSubSystem::Instance()->Initialize();
	RenderSubSystem::Instance()->Initialize();
	EventSubSystem::Instance()->Initialize();
	ResourceSubSystem::Instance()->Initialize();
	SceneSubSystem::Instance()->Initialize();
	SaveSubSystem::Instance()->Initialize();

	//running = true;
	//gameThread = thread(GameLoop);
	//renderThread = thread(RenderLoop);

	LOG("Engine Start completed", "ENGINE", terminal_color::cyan);

	PongScene* _s = new PongScene("PongScene");

	SceneSubSystem::Instance()->ChangeScene("PongScene");

	toExit = false;
	EngineLoop();
}

void Engine::InitializeWindow()
{
	ContextSettings _settings;
	_settings.antiAliasingLevel = 4;
	mainWindow = make_unique<RenderWindow>();
	mainWindow->create(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Custom Engine", State::Windowed, _settings);
	mainWindow->setFramerateLimit(60);
	mainWindow->setKeyRepeatEnabled(false);
}

void Engine::Closing()
{
	toExit = true;
}

void Engine::Shutdown()
{
	LOG("Engine shutting down...", "ENGINE", terminal_color::cyan);
	// Clear all threads
	//running = false;
	//if (gameThread.joinable())
	//	gameThread.join();
	//if (renderThread.joinable())
	//	renderThread.join();

	// Shutdown SubSystems
	SceneSubSystem::Instance()->Shutdown();
	GameSubSystem::Instance()->Shutdown();
	RenderSubSystem::Instance()->Shutdown();
	EventSubSystem::Instance()->Shutdown();
	ResourceSubSystem::Instance()->Shutdown();
	SaveSubSystem::Instance()->Shutdown();

	LOG("Engine shutdown completed", "ENGINE", terminal_color::cyan);
}

void Engine::GameLoop()
{
	//while (running)
	//{
	//	auto _startFrame = chrono::system_clock::now();

	//	// --- UPDATE SUBSYSTEM ---
	//	GameSubSystem::Instance()->UpdateAll(/*deltaTime*/);

	//	// --- FRAME READY ---
	//	{
	//		unique_lock _lock(frameMutex);
	//		frameUpdated = true;
	//		frameRendered = false;
	//	}
	//	frameVar.notify_all();

	//	// --- WAIT FOR RENDER COMPLETE ---
	//	{
	//		unique_lock _lock(frameMutex);
	//		frameVar.wait(_lock, [] { return frameRendered || !running; });
	//	}

	//	auto _endFrame = chrono::system_clock::now();
	//	auto _delta = chrono::duration<double, milli>(_endFrame - _startFrame);
	//	cout << "[GameThread] Frame time: " << _delta.count() << "ms\n";

	//	this_thread::sleep_for(16ms); // ~60 FPS rendu
	//}
}

void Engine::RenderLoop()
{
	//while (running && mainWindow->isOpen()) 
	//{
	//	// --- WAIT FOR FRAME READY ---
	//	{
	//		unique_lock _lock(frameMutex);
	//		frameVar.wait(_lock, [] { return frameUpdated || !running; });
	//	}

	//	if (!running) 
	//		break;

	//	// --- RENDER SUBSYSTEM ---
	//	mainWindow->clear();
	//	RenderSubSystem::Instance()->RenderAll();
	//	mainWindow->display();

	//	// --- SIGNAL FRAME COMPLETE ---
	//	{
	//		unique_lock _lock(frameMutex);
	//		frameUpdated = false;
	//		frameRendered = true;
	//	}
	//	frameVar.notify_all();
	//}
}

void Engine::EngineLoop()
{
	Clock _clock; // Start the clock
	float _deltaTime = 0.f;

	while (mainWindow->isOpen())
	{
		// Events
		EventSubSystem::Instance()->HandleEvents();

		if (toExit)
			break;

		// Update
		GameSubSystem::Instance()->Updating(_deltaTime);

		// Render
		mainWindow->clear();
		RenderSubSystem::Instance()->Rendering();
		mainWindow->display();

		_deltaTime = _clock.restart().asSeconds();
		//LOG(to_string(_deltaTime) + " s", "FRAME", terminal_color::yellow);
	}

	Shutdown();
}