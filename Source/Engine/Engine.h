#pragma once

#include <future>
#include "Utils/Utils.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600

/// <summary>
/// The main class of the CustomEngine
/// </summary>
class Engine final
{
	static inline bool toExit = false;
	static inline unique_ptr<RenderWindow> mainWindow = nullptr;

	//static inline atomic<bool> running;
	//static inline thread gameThread;
	//static inline thread renderThread;
	//static inline mutex frameMutex;
	//static inline condition_variable frameVar;
	//static inline bool frameUpdated = false;
	//static inline bool frameRendered = false;

public:
	static inline RenderWindow* GetMainWindow() { return mainWindow.get(); }
	static inline Vector2u GetMainWindowSize() { return mainWindow->getSize(); }

public:
	/// <summary>
	/// Initialize the engine and subSystems (game, rendering, event, resource, scene)
	/// </summary>
	static void Initialization();
	/// <summary>
	/// Initialize the engine's window
	/// </summary>
	static void InitializeWindow();
	/// <summary>
	/// Start shutdown procedure
	/// </summary>
	static void Closing();
	/// <summary>
	/// Shutdown the engine and SubSystems
	/// </summary>
	static void Shutdown();

private:
	/// <summary>
	/// Loop for update
	/// </summary>
	static void GameLoop();
	/// <summary>
	/// Loop for render
	/// </summary>
	static void RenderLoop();

	/// <summary>
	/// Main loop of engine
	/// </summary>
	static void EngineLoop();
};

// Initialize Engine
//  Initialize Game
//      Initialize Level
//          Game loop
//              Input/Event
//              Update
//              Render
//				(SubSystem)
//      Cleanup Level
//  Cleanup Game
// Cleanup Engine
