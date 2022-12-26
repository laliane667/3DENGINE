#ifndef GAME_H
#define GAME_H
#include "header.h"
#include "engine.h"
#include "world.h"
#include "model.h"

struct PlaneCollider
{
    PlaneCollider(){}
    ~PlaneCollider(){}

    glm::vec3 Normal;

};

struct Object
{
    Transform* m_transform = nullptr;
    Mesh* m_mesh = nullptr;
    std::vector<PlaneCollider*> m_colliders;
    std::string m_tag;

    glm::vec3 m_force;
    glm::vec3 m_externalForce;
    glm::vec3 m_speed;
    glm::vec3 m_orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_collisionNormal;
    float m_mass = 100;


    Object(Transform* t,Mesh* m, std::string s){m_transform = t; m_mesh = m ; m_tag = s;}
    ~Object(){}

    void Init();
    void Update();
    void Draw(Shader* s, Camera* c){m_mesh->Draw(*s,*c,m_transform);}
    void Clear();

    void Translate(float x, float y, float z){m_transform->Translate(x,y,z);}
    void reScale(float x, float y, float z){m_transform->reScale(x,y,z);}
    void setNewPos(glm::vec3 newPos){m_transform->setNewPos(newPos);}
    void addImpulse(glm::vec3 impulse){m_force += impulse;}


    void enableCollision(bool b){m_enableCollision = b;}
    void enablePhysics(bool b){m_enablePhysics = b;}
    void setIsOnFloor(bool b){m_isOnFloor = b;}
    bool isCollisionActive(){return m_enableCollision;}
    bool isPhysicsActive(){return m_enablePhysics;}
    bool isOnFloor(){return m_isOnFloor;}

    bool collide(Object* obj, glm::vec3& N, float& collisionDescription);
    bool doesInteract(Object* obj, glm::vec3 normal, const glm::vec3& offset, const glm::vec3& velo, float& t);
    bool FindMTD(glm::vec3 axis[12], float depth[12], int Size, glm::vec3& normal, float& t);

    Transform* getTransform(){return m_transform;}
    glm::vec3 getPos(){return m_transform->Position;}
    std::string getTag(){return m_tag;}

    private:
        bool m_enableCollision = false;
        bool m_enablePhysics = false;
        bool m_isOnFloor = false;

};

class World;

class Player
{
    public:
        Player(Object* body, Camera* cam, std::string name){m_obj = body; m_cam = cam; m_name = name;}
        ~Player(){}

        //void Initialize(string name);
        void Display();
        void Update();
        void Input();
        void MouseInput();
        void Delete();
        float speed = 1000;

        Object* getObj(){return m_obj;}

    private:
        std::string m_name;
        //float m_mass = 75;

        Object* m_obj = nullptr;
        Camera* m_cam = nullptr;
        bool m_jumpEnable = true;




};

class Game
{
    public:
        static Game* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Game();
        }
        ~Game(){}

        void inGame();
        void graphicsInGame();
        void initialize();
        void Clear();

        void addPlayer(Player* player){m_players.push_back(player);}
        Player* getPlayer(int i){return m_players[i];}

        World* getWorld(){return m_world;}

        glm::vec3 gravity = glm::vec3(0.0f, -1000, 0.0f);

        ///CONSTANTES

    private:
        static Game* s_Instance; ///UNIQUE INSTANCE DE LA CLASSE ENGINE, OMNIPRESENTE DU DEBUT A LA FIN DU JEU
        World* m_world;
        vector<Player*> m_players;

};

#endif // GAME_H
