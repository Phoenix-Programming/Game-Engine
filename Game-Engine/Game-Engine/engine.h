#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include <vector>

#include "window.h"
#include "game_object.h"
#include "renderable.h"

class Engine
{
public:
    Window window;

    Engine();

    // Called once at the start
    // Creates the window and similar processes
    // Not the same Start as the one that all GameObjects have
    // That Start will be called by AddObject
    void Start();
    // advance one frame
    // this should call Update for each
    // component on each GameObject
    bool Update();
    // Calls Close functions on all GameObjects
    void Close();
    // registers a GameObject so that it will be updated and drawn every frame
    // this should call Start on each component of the object
    void AddObject(GameObject object);
    // Executes Start, Update repeatedly, and Close
    void Execute();
    
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
