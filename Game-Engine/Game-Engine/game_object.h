#ifndef ENGINE_GAME_OBJECT_H_
#define ENGINE_GAME_OBJECT_H_

#include <string>
#include <vector>

#include "common.h"

// like a unity component, derived classes override Start and Update
// to add functionality
class Component {
 public:
  // called when the GameObject this component is attached to
  // is first registered
  virtual void Start();
  // called every subsequent frame
  virtual void Update();

  // the GameObject this component is attached to
  GameObject* parent;
};

// like a unity gameobject, has a position and a set of components
class GameObject {
 public:
  // adds a component and sets the component's parent to this object
  void AddComponent(Component component);

  std::string name;
  Vector3 position;
  bool enabled;
  std::vector<Component> components;
};

#endif  // ENGINE_GAME_OBJECT_H_
