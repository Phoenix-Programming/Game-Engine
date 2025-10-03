#pragma once

#include "common.h"

// like a unity component, derived classes override Start and Update to add functionality
class Component {
public:
	// the GameObject this component is attached to
	GameObject* parent;

	// called when the GameObject this component is attached to is first registered
	virtual void Start();
	// called every subsequent frame
	virtual void Update();
};

// like a unity gameobject, has a position and a set of components
class GameObject {
public:
	Vector3 position;

	std::vector<Component> components;

	// adds a component and sets the component's parent to this object
	void AddComponent(Component component);
};
