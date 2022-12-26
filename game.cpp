#include "game.h"

Game *Game::s_Instance = nullptr;

/*void Player::Initialize(string name)
{
    glm::vec3 pos;
    m_name = name;
    if(m_obj != nullptr)
        pos = m_obj->getTransform()->Position;


}*/



void Player::Update()
{
    //cout << m_obj->m_collisionNormal.y << endl;
    //Input();
    //m_obj->m_force = poids + m_externalForces; ///SOMME DES FORCES
    GLFWwindow* window = Engine::GetInstance()->getWindow();
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    float dt = Engine::GetInstance()->getDeltaTime();

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && m_jumpEnable == true)
	{
		m_obj->m_externalForce.y += speed * 16;
		m_jumpEnable = false;
	}
	else if(!(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) && m_jumpEnable == false)
        m_jumpEnable = true;

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		m_obj->m_externalForce.y += -speed;
	}

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_obj->m_externalForce.x += speed * -((glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).x);
		m_obj->m_externalForce.z += speed * -((glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).z);

	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_obj->m_externalForce.x += speed * -((glm::cross(m_obj->m_orientation, Up)).x);
		m_obj->m_externalForce.z += speed * -((glm::cross(m_obj->m_orientation, Up)).z);

	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_obj->m_externalForce.x += speed * ((glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).x);
		m_obj->m_externalForce.z += speed * ((glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).z);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_obj->m_externalForce.x += speed * ((glm::cross(m_obj->m_orientation, Up)).x);
		m_obj->m_externalForce.z += speed * ((glm::cross(m_obj->m_orientation, Up)).z);
	}

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		m_obj->m_force = glm::vec3(0,0,0);
		m_obj->m_externalForce = glm::vec3(0,0,0);
		m_obj->m_speed = glm::vec3(0,0,0);
	}

   // glm::vec3 poids = m_obj->m_mass*Game::GetInstance()->gravity;
    //glm::vec3 R = m_obj->m_collisionNormal * poids;


   /* m_obj->m_speed += (m_obj->m_force/ m_obj->m_mass) * dt;

    ApplyLinearCollisionImpulse(m_obj, 0.5);

    if(abs(m_externalForces.x) > 0)
        m_externalForces.x += -m_externalForces.x*0.1;
    if(abs(m_externalForces.y) > 0)
        m_externalForces += -m_externalForces.y*0.1;
    if(abs(m_externalForces.z) > 0)
        m_externalForces.z += -m_externalForces.z*0.1;

    if(abs(m_externalForces.x) < 0.01)
        m_externalForces.x = 0;
    if(abs(m_externalForces.y) < 0.01)
        m_externalForces.y = 0;
    if(abs(m_externalForces.z) < 0.01)
        m_externalForces.z = 0;*/

    //if(m_obj->m_force.x == 0) m_obj->m_speed.x += -m_obj->m_speed.x*0.1;
    //if(m_obj->m_force.y == 0) m_obj->m_speed.y += -m_obj->m_speed.y*0.1;
    //if(m_obj->m_force.z == 0) m_obj->m_speed.z += -m_obj->m_speed.z*0.1;*/

    /*if(abs(m_obj->m_speed.x) > 0)
        m_obj->m_speed.x += -m_obj->m_speed.x*0.1;
    if(abs(m_obj->m_speed.y) > 0)
        m_obj->m_speed.y += -m_obj->m_speed.y*0.1;
    if(abs(m_obj->m_speed.z) > 0)
        m_obj->m_speed.z += -m_obj->m_speed.z*0.1;

    if(abs(m_obj->m_speed.x) < 0.01)
        m_obj->m_speed.x = 0;
    if(abs(m_obj->m_speed.y) < 0.01)
        m_obj->m_speed.y = 0;
    if(abs(m_obj->m_speed.z) < 0.01)
        m_obj->m_speed.z = 0;*/

    //m_obj->Translate(m_obj->m_speed.x *dt, m_obj->m_speed.y*dt, m_obj->m_speed.z *dt);
    //m_obj->Translate(m_obj->m_speed.x, m_obj->m_speed.y, m_obj->m_speed.z);
    m_cam->Position.x = m_obj->m_transform->Position.x;
    m_cam->Position.y = m_obj->m_transform->Position.y + 1;
    m_cam->Position.z = m_obj->m_transform->Position.z;

    //cout << m_obj->m_transform->Position.y << endl;


    //m_externalForces = glm::vec3(0,0,0);
}

void Player::Input()
{
    /*GLFWwindow* window = Engine::GetInstance()->getWindow();
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_obj->m_speed.x += speed * -(glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).x;
		m_obj->m_speed.z += speed * -(glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).z;

	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_obj->m_speed.x += speed * -(glm::cross(m_obj->m_orientation, Up)).x;
		m_obj->m_speed.z += speed * -(glm::cross(m_obj->m_orientation, Up)).z;

	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_obj->m_speed.x += speed * (glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).x;
		m_obj->m_speed.z += speed * (glm::cross(glm::cross(m_obj->m_orientation, Up), Up)).z;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_obj->m_speed.x += speed * (glm::cross(m_obj->m_orientation, Up)).x;
		m_obj->m_speed.z += speed * (glm::cross(m_obj->m_orientation, Up)).z;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		m_obj->m_speed.y += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		m_obj->m_speed.y += -speed;
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE)
	{
		speed = 0.1f;
	}

*/
}

void Player::MouseInput()
{
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    GLFWwindow* window = Engine::GetInstance()->getWindow();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // Stores the coordinates of the cursor
    double mouseX;
    double mouseY;
    // Fetches the coordinates of the cursor
    glfwGetCursorPos(window, &mouseX, &mouseY);

    // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
    // and then "transforms" them into degrees
    float rotX = m_cam->sensitivity * (float)(mouseY - (SCR_HEIGHT / 2)) / SCR_HEIGHT;
    float rotY = m_cam->sensitivity * (float)(mouseX - (SCR_WIDTH / 2)) / SCR_WIDTH;

    // Calculates upcoming vertical change in the Orientation
    glm::vec3 newOrientation = glm::rotate(m_obj->m_orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_obj->m_orientation, Up)));

    // Decides whether or not the next vertical Orientation is legal or not
    if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
    {
        m_obj->m_orientation = newOrientation;
    }

    // Rotates the Orientation left and right
    m_obj->m_orientation = glm::rotate(m_obj->m_orientation, glm::radians(-rotY), Up);

    // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
    glfwSetCursorPos(window, (SCR_WIDTH / 2), (SCR_HEIGHT / 2));

    m_cam->Orientation = m_obj->m_orientation;
    //m_cam->Position = m_obj->m_transform->Position;


}

void Player::Display()
{

}

void Game::initialize()
{
    Engine::GetInstance()->setShader(new Shader("resource/Shaders/default.vert", "resource/Shaders/default.frag"));
	Engine::GetInstance()->setLightShader(new Shader("resource/Shaders/light.vert", "resource/Shaders/light.frag"));
    Engine::GetInstance()->setTransparancyShader(new Shader("resource/Shaders/default.vert", "resource/Shaders/transparency.frag"));

    m_world = new World();
    m_world->initialize();

    string name = Engine::GetInstance()->getUserName();
    Object* body = m_world->getObj(0);
    Camera* cam = Engine::GetInstance()->getCamera();

    m_players.push_back(new Player(body,cam,name));

    cout << body->getTag() << endl;

    //Engine::GetInstance()->getCamera()->allowControl(true);
    Engine::GetInstance()->set_etape("INGAME");
}

void Game::inGame()
{
    m_world->update(m_players);
    m_players[0]->Update();

}

void Game::graphicsInGame()
{
    m_players[0]->MouseInput();
    m_world->display();
}

void Object::Init()
{
        for(int m = 0; m < 3 ; m++)
        {
            PlaneCollider* p = nullptr;
            if(isCollisionActive())
            {
                p = new PlaneCollider();
                switch(m)
                {
                    case 0: p->Normal = m_mesh->vertices[4].normal; break;
                    case 1: p->Normal = m_mesh->vertices[8].normal; break;
                    case 2: p->Normal = m_mesh->vertices[16].normal; break;
                    case 3: p->Normal = m_mesh->vertices[12].normal; break;
                    case 4: p->Normal = m_mesh->vertices[0].normal; break;
                    case 5: p->Normal = m_mesh->vertices[20].normal; break;
                }
            }
            m_colliders.push_back(p);
        }
}

void Object::Update()
{
	float dt = Engine::GetInstance()->getDeltaTime();
    m_force += m_externalForce;
    m_speed += m_force/m_mass*dt;

    Translate(m_speed.x *dt, m_speed.y*dt, m_speed.z *dt);

        if(abs(m_speed.x) > 0)
            m_speed.x += -m_speed.x*0.05;
        if(abs(m_speed.z) > 0)
          m_speed.z += -m_speed.z*0.05;


    if(abs(m_speed.x) < 0.1)
        m_speed.x = 0;
    if(abs(m_speed.y) < 0.1)
        m_speed.y = 0;
    if(abs(m_speed.z) < 0.1)
        m_speed.z = 0;

    m_force.x = 0; m_force.y = 0; m_force.z = 0;
    m_externalForce.x = 0; m_externalForce.y = 0; m_externalForce.z = 0;
}

bool Object::collide(Object* other, glm::vec3& N, float& collisionDescription)
{
    glm::vec3 offset = other->getPos() - getPos();
    float length = glm::length(offset);

    glm::vec3 velo = other->m_speed - m_speed;
    float depth[6];
    glm::vec3 axis[6];

    int i = 0, j = 0;
    float t = 1.0f;

    for(i = 0; i < 3; i++)
    {
        if(!doesInteract(other, m_colliders[i]->Normal, offset, velo, t)) return false;
        axis[j] = m_colliders[i]->Normal;
        depth[j] = t;
        j++;
    }

    for(i = 0; i < 3; i++)
    {
        if(!other->doesInteract(this, m_colliders[i]->Normal, offset, velo, t)) return false;
        axis[j] = other->m_colliders[i]->Normal;
        depth[j] = t;
        j++;
    }

    glm::vec3 norm;

    if(!FindMTD(axis, depth, 6, norm, t)) return false;



    //if(glm::dot(norm,offset) < 0.0f)  norm = norm*(-1.0f);

    //normal = normal*(-1.0f);
    //if(normal.x == -0) normal.x = 0;
    //if(normal.y == -0) normal.y = 0;
    //if(normal.z == -0) normal.z = 0;
    //cout << t << endl;
    //if(t == -1) return false;
    N = norm;
    collisionDescription = t;
    return true;
}

bool Object::doesInteract(Object* other, glm::vec3 normal, const glm::vec3& offset, const glm::vec3& velo, float& t)
{
    float max0 = glm::dot(normal, this->m_transform->Position + this->m_transform->Scale);
    float min0 = glm::dot(normal, this->m_transform->Position);

    float max1 = glm::dot(normal, other->m_transform->Position + other->m_transform->Scale);
    float min1 = glm::dot(normal, other->m_transform->Position);

    /*float h;
    h = glm::dot(offset, normal);
    min0 += h;
    max0 += h;*/
   // cout << max0 << " et " << min0 << endl;

    float d0 = min0 - max1;
    float d1 = min1 - max0;

    float v;
    float t0, t1, temp;

    if(d0 > 0.0f || d1 > 0.0f)
    {
        v = glm::dot(velo, normal);
        if(fabs(v) < 0.0000001f) return false;

        t0 = -d0/v;
        t1 = d1/v;

        if(t0 > t1) {temp = t0; t0 = t1; t1 = temp;}
        t = (t0 > 0.0f)? t0 : t1;

        if(t < 0.0f || t > 1.0f) return false;

        return true;
    }
    else
    {
        t = (d0 > d1)? d0 : d1;
        return true;
    }
    return false;
}

bool Object::FindMTD(glm::vec3 axis[6], float depth[6], int Size, glm::vec3& normal, float& t)
{
    float minDepth = -1;
    int indexNormalCollision = 0;
    for(int i = 0; i < Size; i++)
    {
        if(depth[i] <= 0)
        {
            if(depth[i] > minDepth)
            {
                minDepth = depth[i];
                indexNormalCollision = i;
            }
        }
        else return false;

    }
    t = depth[indexNormalCollision];
    normal = axis[indexNormalCollision];

    return true;
}

void Object::Clear()
{
    for(unsigned long i = 0; i < m_colliders.size(); i++)
        if(m_colliders[i] != nullptr)
            delete m_colliders[i];
    if(m_transform != nullptr)
        delete m_transform;
    if(m_mesh != nullptr)
        delete m_mesh;

}

void Player::Delete()
{
    //m_obj->Clear();
    if(m_obj != nullptr)
        delete m_obj;
    if(m_cam != nullptr)
        delete m_cam;
}

void Game::Clear()
{
    for(unsigned long i = 0; i < m_players.size(); i++)
    {
        //m_players[i]->Delete();
        delete m_players[i];
    }
    if(m_world != nullptr)
    {
        m_world->Clear();
        delete m_world;
    }

}
