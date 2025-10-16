#ifndef ENGINE_RENDERABLE_H_
#define ENGINE_RENDERABLE_H_

#include <string>

#include "game_object.h"

// RenderableComponent is separate from Component so that you can separate
// Update and Draw into two functions, and so that you can easily
// differentiate between components that render and those that don't
class RenderableComponent : public Component {
 public:
  // if a Component is a RenderableComponent, Draw will be called every frame
  // in addition to Update
  virtual void Draw();
};

// a RenderableComponent that renders a string to the screen
class RenderableText : public RenderableComponent {
 public:
  std::string content;

  explicit RenderableText(std::string content);

  // this should use opengl to render some text to the screen
  void Draw();
};

#endif
