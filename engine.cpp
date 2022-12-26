#include "engine.h"

Engine *Engine::s_Instance = nullptr;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

float rectangleVertices[] =
{
	// Coords    // texCoords
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f,

	 1.0f,  1.0f,  1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f
};

bool Engine::initialize()
{
    cout << "Engine init..." << endl;
    set_etape("MENU");
    User u; m_user = u;
    srand(time(NULL));

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, m_gameName.c_str(), NULL, NULL);

    if (m_window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return false;
    }

    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);

    //glEnable(GL_FRAMEBUFFER_SRGB);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glFrontFace(GL_CCW);

    m_camera = new Camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));
    m_GUIS.push_back(new GUI(0));


    return true;

}


void Engine::run()
{

        //m_model->Draw(*m_shaderProgram, *m_camera);
        m_time = (float)glfwGetTime();
        m_deltaTime = m_time - m_lastTime;
        m_counter++;
        if(m_deltaTime >= 1.0 / 120.0)
        {
            m_framePerSecond = (1.0 / m_deltaTime) * m_counter;
            std::string FPS = std::to_string(m_framePerSecond);
            std::string ms = std::to_string((m_deltaTime / m_counter) * 1000);
            std::string title = m_gameName + FPS + " Fps | " + ms + " Ms";
            glfwSetWindowTitle(m_window, title.c_str());
            m_lastTime = m_time;
            m_counter = 0;
            directory();
        }
        processInput(m_window);
        glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(m_camera->allowControl())
            m_camera->Inputs(m_window);
        m_camera->updateMatrix(45.0f, 0.1f, 100.0f);


        gaphicsDirectory();

        glfwSwapBuffers(m_window);
        glfwPollEvents();
}


void Engine::directory()
{
    if(get_etape() == "INITGAME")
        Game::GetInstance()->initialize();
    else if(get_etape() == "INGAME")
        Game::GetInstance()->inGame();
}

void Engine::gaphicsDirectory()
{
    if(get_etape() == "MENU")
        GetInstance()->Menu();
    else if(get_etape() == "INGAME")
        Game::GetInstance()->graphicsInGame();
}

void Engine::Menu()
{
    m_GUIS[0]->Update();
    m_GUIS[0]->Display();
}

void Engine::CleanMenu()
{
/*    m_GUIS[0]->Delete();
    delete m_GUIS[0];*/
}

void Engine::quit()
{
    cout << " Starting clear... " << endl;
    for(unsigned long i = 0; i < m_GUIS.size(); i++)
    {
        if(m_GUIS[i]!= nullptr)
        m_GUIS[i]->Delete();
        delete m_GUIS[i];
    }
    if(m_shaderProgram != nullptr)
    {
        m_shaderProgram->Delete();
        delete m_shaderProgram;
    }
    if(m_lightShader != nullptr)
    {
        m_lightShader->Delete();
        delete m_lightShader;
    }
    if(m_transparancyShader != nullptr)
    {
        m_transparancyShader->Delete();
        delete m_transparancyShader;
    }
    //delete m_model;

    Game::GetInstance()->Clear();

    delete Game::GetInstance();

    if(m_camera != nullptr)
        delete m_camera;
    glfwDestroyWindow(Engine::GetInstance()->getWindow());
	glfwTerminate();
    cout << "Quit success..." << endl;
}

///========================================================================================================================///

Vertex buttonVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-1, -0.1f, 0),    glm::vec3(0, -1, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3( 1, -0.1f, 0),    glm::vec3(0, -1, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3( 1,  0.1f, 0),    glm::vec3(0, -1, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3(-1,  0.1f, 0),    glm::vec3(0, -1, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},
};

GLuint buttonIndices[] =
{
	0, 3, 2,
	0, 2, 1,
};

void GUI::Init()
{
    cout << "GUI Initializing..." << endl;
    Engine::GetInstance()->getCamera()->allowControl(false);
    Engine::GetInstance()->setShader(new Shader("resource/Shaders/gui.vert", "resource/Shaders/gui.frag"));

    Texture textures[]
	{
		Texture("resource/Textures/package/GUI/concrete/concrete.jpg", "diffuse", 0),
		Texture("resource/Textures/package/GUI/concrete/concreteSpec.jpg", "specular", 1)
	};

    std::vector <Vertex> buttonVerts(buttonVertices, buttonVertices + sizeof(buttonVertices) / sizeof(Vertex));
	std::vector <GLuint> buttonInd(buttonIndices, buttonIndices + sizeof(buttonIndices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

    Engine::GetInstance()->getShader()->Activate();

    m_meshes.push_back(new Mesh(buttonVerts, buttonInd, tex));
}

void GUI::Update()
{
    if (glfwGetMouseButton(Engine::GetInstance()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double xpos, ypos;
        //getting cursor position
        glfwGetCursorPos(Engine::GetInstance()->getWindow(), &xpos, &ypos);
        Engine::GetInstance()->CleanMenu();
        Engine::GetInstance()->set_etape("INITGAME");
    }

}

void GUI::Display()
{
    Shader shad = *Engine::GetInstance()->getShader();
    Camera cam = *Engine::GetInstance()->getCamera();
    Transform* t = nullptr;

    for(unsigned long i = 0; i < m_meshes.size(); i++)
    {
        m_meshes[i]->Draw(shad,cam,t);
    }
}

void GUI::Delete()
{
    for(unsigned long i = 0; i < m_meshes.size(); i++)
    {
        delete m_meshes[i];
    }
}
