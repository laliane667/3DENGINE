#ifndef ENGINE_H
#define ENGINE_H
#include "header.h"
#include "game.h"

#include "model.h"

class User
{
    private:
        string m_UserName;
    public:
        User(){}
        ~User(){}

        void setUserName(string name){m_UserName = name;}
        string getUserName(){return m_UserName;}
};
///================================================================\\ GUI // =====================================================================

class GUI
{
    public:
        GUI(int id){m_id = id; Init();}
        void Show(){m_active = true;}
        void Hide(){m_active = false;}
        void Init();
        void Update();
        void Display();
        void Delete();
        ~GUI(){}

    private:
        bool m_active = false;
        vector<Mesh*> m_meshes;
        int m_id;

};

///================================================================\\ ENGINE // =====================================================================

class Engine
{
    private:
        static Engine* s_Instance; ///UNIQUE INSTANCE DE LA CLASSE ENGINE, OMNIPRESENTE DU DEBUT A LA FIN DU JEU

        ///GLFW VARIABLES///
        GLFWwindow* m_window;
        Camera* m_camera;
        Shader* m_shaderProgram = nullptr, *m_lightShader = nullptr, *m_transparancyShader = nullptr;
        vector<GUI*> m_GUIS;
        //Model* m_model;

        ///GAME VARIABLES///
        string m_gameName = "Jeu_v:0.1 | ";
        string m_etapeActuelle; ///AIGUILLAGE QUI PERMET DE SE DEPLACER ENTRE LES DIFFERENTS MENUS
        User m_user;
        double m_framePerSecond = 0;
        bool m_loopDone = false;
        double m_time = 0, m_lastTime = glfwGetTime(), m_deltaTime = 0;
        unsigned int m_counter = 0;

    public:
        static Engine* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
        }
        ~Engine(){}

        bool initialize();
        void run();

        void directory();
        void gaphicsDirectory();

        void quit();

        void Menu();
        void CleanMenu();

        GLFWwindow* getWindow(){return m_window;}
        Camera* getCamera(){return m_camera;}
        Shader* getShader(){return m_shaderProgram;}
        Shader* getTransparancyShader(){return m_transparancyShader;}
        Shader* getLightShader(){return m_lightShader;}


        void setShader(Shader* s){m_shaderProgram = s;}
        void setTransparancyShader(Shader* s){m_transparancyShader = s;}
        void setLightShader(Shader* l){m_lightShader = l;}

        void set_etape(string s){m_etapeActuelle = s;}
        string get_etape(){return m_etapeActuelle;}

        string getUserName(){return m_user.getUserName();}

        double getDeltaTime(){return m_deltaTime;}


};

#endif // ENGINE_H
