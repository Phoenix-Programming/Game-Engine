#include "engine.h"

Engine::Engine() :
	window(Window(defaultWindowWidth, defaultWindowHeight)) { }

void Engine::Start()
{
	window.Start();
}

bool Engine::Update()
{
	window.Update();
	
	return !window.ShouldClose();
}

void Engine::Close()
{
	window.Close();
}

void Engine::Execute()
{
	Start();
	while (Update());
	Close();
}