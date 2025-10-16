#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include <vector>

#include "game_object.h"
#include "renderable.h"

class Game {
 public:
  // registers a GameObject so that it will be updated and drawn every frame
  // this should call Start on each component of the object
  void AddObject(GameObject object);

  // advance one frame.
  // this should call Update and possibly Draw for each
  // component in each tracked object
  void Tick();

  int windowWidth, windowHeight;
  std::vector<GameObject> objects;
};

#endif  // ENGINE_ENGINE_H_

/**

this is what an example game that displays some text should look like:

class MyGame : Game
{
public:
    void Run()
    {
        // create a new game object
        GameObject text = GameObject();

        // add a new RenderableText component to the game object
        text.AddComponent(RenderableText("Hello World"));

        // register the game object, which will call Start on it's RenderableText component
        Game::AddObject(text);

        // advance one frame, which will call Update and Draw on the game object's RenderableText component
        Game::Tick();
    }
}

int main()
{
    MyGame myGame;
    myGame.Run();
}

*/
