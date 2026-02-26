#include "engine.h"

Engine::Engine() :
	window(Window(defaultWindowWidth, defaultWindowHeight)) { }

void Engine::Start()
{
	window.Start();

	// THIS IS TEMPORARY AND SHOULD BE MOVED INTO GAME
	closeWindowBind = Keybind({ GLFW_KEY_ESCAPE, GLFW_KEY_E });
	input.AddKeybind(closeWindowBind);
}

bool Engine::Update()
{
	window.Update();
	input.UpdateKeybinds(window);
	
	if (closeWindowBind.held)
		glfwSetWindowShouldClose(window.window, GLFW_TRUE);
	
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