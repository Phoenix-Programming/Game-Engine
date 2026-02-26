#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include "Window.h"

class Keybind
{
private:
	void Update(const Window& window);

public:
	std::vector<int> keys;
	bool pressed, held, released;

	Keybind(const std::vector<int>& keys = { }) :
		keys(keys), pressed(false), held(false), released(false) { }

	friend class InputHandler;
};

class InputHandler
{
private:
	std::vector<Keybind*> keybinds;

public:
	void AddKeybind(Keybind& keybind);
	void RemoveKeybind(const Keybind& keybind);

	void UpdateKeybinds(const Window& window) const;
};

#endif