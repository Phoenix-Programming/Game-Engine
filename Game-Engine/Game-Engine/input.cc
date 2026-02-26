#include "input.h"

void Keybind::Update(const Window& window)
{
	// Check if any keys are being held
	for (int key : keys)
		if (glfwGetKey(window.window, key) == GLFW_PRESS)
		{
			// A key is being held
			pressed = !held;
			released = false;
			held = true;
			return;
		}

	// None of the bound keys were being held
	pressed = false;
	released = held;
	held = false;
}

void InputHandler::AddKeybind(Keybind& keybind)
{
	keybinds.push_back(&keybind);
}

void InputHandler::RemoveKeybind(const Keybind& keybind)
{
	std::remove(keybinds.begin(), keybinds.end(), &keybind);
}

void InputHandler::UpdateKeybinds(const Window& window) const
{
	for (Keybind* keybind : keybinds)
		keybind->Update(window);
}