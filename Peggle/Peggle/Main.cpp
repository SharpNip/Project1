#include "Utils.h"
#include "App.h"
#include "Engine.h"
#include "Peggle.h"

// THis is the main, which handles most of the necessary non-game related stuff

int WINAPI _tWinMain(HINSTANCE hInstance, 
	HINSTANCE prevHInstance, 
	LPTSTR cmd, int showCmd)
{
	Engine* engine = new Engine(hInstance, "Nick Potvin - Peggle");
	gEngine = engine;

	engine->Init();

	Peggle* game = new Peggle();

	int assert = gEngine->Run();

	delete game;
	delete engine;

	return assert;
}
