#include "engine.h"
#include "game.h"
#include "world.h"


int main(void)
{
    if(Engine::GetInstance()->initialize() == false)
    {
        Engine::GetInstance()->quit();
        delete Engine::GetInstance();
        return 0;
    }

    while (!glfwWindowShouldClose(Engine::GetInstance()->getWindow()))
    {
        Engine::GetInstance()->run();
    }

    Engine::GetInstance()->quit();
    delete Engine::GetInstance();
    return 0;
}

