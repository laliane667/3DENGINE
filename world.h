#ifndef WORLD_H
#define WORLD_H

#include "header.h"
#include "engine.h"
#include "model.h"
#include "game.h"

struct Object;
class Player;

class World
{
    public:
        World(){}
        ~World(){}

        void initialize();
        void update(std::vector<Player*> m_players);
        glm::vec3 testCollision(Object* obj, int i);
        void display();
        void Clear();
        Object* getObj(int i){return m_objects[i];}

    private:
        std::vector<Object*> m_objects;
};

#endif // WORLD_H
