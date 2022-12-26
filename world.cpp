#include "world.h"

Vertex blockVertices[] =
{ //     COORDINATES     //
    Vertex{glm::vec3(-0.5, -0.5, -0.5),    glm::vec3(0, -1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3( 0.5, -0.5, -0.5),    glm::vec3(0, -1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3( 0.5, -0.5,  0.5),    glm::vec3(0, -1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3(-0.5, -0.5,  0.5),    glm::vec3(0, -1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},

	Vertex{glm::vec3( 0.5, -0.5, -0.5),    glm::vec3(1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3( 0.5,  0.5, -0.5),    glm::vec3(1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3( 0.5,  0.5,  0.5),    glm::vec3(1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3( 0.5, -0.5,  0.5),    glm::vec3(1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},

	Vertex{glm::vec3( 0.5,  0.5, -0.5),    glm::vec3(0, 1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3(-0.5,  0.5, -0.5),    glm::vec3(0, 1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3(-0.5,  0.5,  0.5),    glm::vec3(0, 1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3( 0.5,  0.5,  0.5),    glm::vec3(0, 1.0f, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},

	Vertex{glm::vec3(-0.5,  0.5, -0.5),    glm::vec3(-1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3(-0.5, -0.5, -0.5),    glm::vec3(-1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3(-0.5, -0.5,  0.5),    glm::vec3(-1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3(-0.5,  0.5,  0.5),    glm::vec3(-1.0f, 0, 0),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},

	Vertex{glm::vec3(-0.5, -0.5,  0.5),    glm::vec3(0, 0, 1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3( 0.5, -0.5,  0.5),    glm::vec3(0, 0, 1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3( 0.5,  0.5,  0.5),    glm::vec3(0, 0, 1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3(-0.5,  0.5,  0.5),    glm::vec3(0, 0, 1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)},

	Vertex{glm::vec3(-0.5, -0.5, -0.5),    glm::vec3(0, 0, -1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 0)},
	Vertex{glm::vec3(-0.5,  0.5, -0.5),    glm::vec3(0, 0, -1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0, 1)},
	Vertex{glm::vec3( 0.5,  0.5, -0.5),    glm::vec3(0, 0, -1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 1)},
	Vertex{glm::vec3( 0.5, -0.5, - 0.5),    glm::vec3(0, 0, -1.0f),     glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1, 0)}
};

GLuint blockIndices[] =
{
	0, 3, 2,
	0, 2, 1,
	4, 7, 6,
	4, 6, 5,
	8, 11, 10,
	8, 10, 9,
	12, 15, 14,
	12, 14, 13,
	16, 19, 18,
	16, 18, 17,
	20, 23, 22,
	20, 22, 21
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.5, -0.5, 0.5)},
	Vertex{glm::vec3(-0.5, -0.5, -0.5)},
	Vertex{glm::vec3(0.5, -0.5, -0.5)},
	Vertex{glm::vec3(0.5, -0.5,  0.5)},
	Vertex{glm::vec3(-0.5, 0.5,  0.5)},
	Vertex{glm::vec3(-0.5, 0.5, -0.5)},
	Vertex{glm::vec3(0.5,  0.5, -0.5)},
	Vertex{glm::vec3(0.5,  0.5,  0.5)}
};

GLuint lightIndices[] =
{
	0, 3, 2,
	0, 2, 1,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

void ApplyLinearCollisionImpulse(Object* obj, float e )
{
    float mass = obj->m_mass;
    float d = glm::dot( obj->m_speed,(obj->m_collisionNormal));
    float j = glm::max( - ( 1 + e ) * d, 0.0f );
    obj->m_speed += j * (obj->m_collisionNormal);
}

void World::initialize()
{
    Texture wood_plank[]
	{
	    Texture("resource/Textures/package/Material/rocky/rocky.png", "diffuse", 0),
		Texture("resource/Textures/package/Material/rocky/rocky_disp.png", "specular", 1),
	};

	Texture trap_door[]
	{
		Texture("resource/Textures/package/Material/glass/iron_trapdoor.png", "diffuse", 0),
		Texture("resource/Textures/package/Material/glass/iron_trapdoor_spec.png", "specular", 1)
	};

    Shader* shad = Engine::GetInstance()->getShader();
    Shader* transp = Engine::GetInstance()->getTransparancyShader();
    Shader* lightShad = Engine::GetInstance()->getLightShader();

    if(shad == nullptr)
        cout << "Shader problem :(" << endl;
    if(transp == nullptr)
        cout << "Transp problem :(" << endl;
    if(lightShad == nullptr)
        cout << "Light problem :(" << endl;


    std::vector <Vertex> blockVerts(blockVertices, blockVertices + sizeof(blockVertices) / sizeof(Vertex));
	std::vector <GLuint> blockInd(blockIndices, blockIndices + sizeof(blockIndices) / sizeof(GLuint));
	std::vector <Texture> tex_wp1(wood_plank, wood_plank + sizeof(wood_plank) / sizeof(wood_plank));
	std::vector <Texture> tex_td1(trap_door, trap_door + sizeof(trap_door) / sizeof(trap_door));


	std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));




    Object* light = new Object(new Transform(),new Mesh(lightVerts, lightInd, tex_wp1),"LIGHT");
    light->reScale(1,1,1);
    light->enableCollision(false);
    light->enablePhysics(false);
    light->Translate(9.0,3.0,5.0);

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::mat4 lightMatrix = light->getTransform()->Matrix;
    glm::vec3 lightPos = light->getTransform()->Position;


    lightShad->Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShad->ID, "model"), 1, GL_FALSE, glm::value_ptr(lightMatrix));
    glUniform4f(glGetUniformLocation(lightShad->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    shad->Activate();
    transp->Activate();
    glUniform4f(glGetUniformLocation(shad->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shad->ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);


	Object* body = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_wp1),"PLAYER0");
    //body->reScale(0.25f,1,0.25f);
    body->Translate(5,10,5);
    body->enableCollision(true);
    body->enablePhysics(true);
    m_objects.push_back(body);
    m_objects.push_back(light);

	for(unsigned int j = 0; j < 20; j++)
    {
        for(unsigned int i = 0; i < 20; i++)
        {
            Object* o = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_wp1),"BLOCK");
            o->Translate(i,0,j);
            o->enableCollision(true);
            o->enablePhysics(false);
            m_objects.push_back(o);
        }
    }
    Object* C = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1),"BLOCK_TRANSP");
    C->reScale(0.5f,0.5f,0.5f);
    C->Translate(7,1,5);
    C->enableCollision(true);
    C->enablePhysics(false);
    m_objects.push_back(C);

    Object* C1 = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1),"BLOCK_TRANSP");
    C1->reScale(0.5f,0.5f,0.5f);
    C1->Translate(7.5,1,5);
    C1->enableCollision(true);
    C1->enablePhysics(false);
    m_objects.push_back(C1);

    /*Object* C1 = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1),"BLOCK_TRANSP");
    C1->Translate(7,2,5);
    C1->enableCollision(true);
    C1->enablePhysics(false);
    m_objects.push_back(C1);

    Object* C2 = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1),"BLOCK_TRANSP");
    C2->Translate(7,3,5);
    C2->enableCollision(true);
    C2->enablePhysics(false);
    m_objects.push_back(C2);

    Object* C3 = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1 ),"BLOCK_TRANSP");
    C3->Translate(8,3,5);
    C3->enableCollision(true);
    C3->enablePhysics(false);
    m_objects.push_back(C3);

    Object* C4 = new Object(new Transform(),new Mesh(blockVerts, blockInd, tex_td1 ),"BLOCK_TRANSP");
    C4->Translate(7,20,4);
    C4->enableCollision(true);
    C4->enablePhysics(true);
    m_objects.push_back(C4);*/

    for(unsigned long l = 0; l < m_objects.size(); l++)
    {
        m_objects[l]->Init();
    }
}

void World::update(std::vector<Player*> m_players)
{
    glm::mat4 lightMatrix;
    glm::vec3 lightPos;

    glm::vec3 N;
    float t = 0.0f;
    bool ret = false;
    bool indexOverFlow = false;

    for(unsigned long i = 0; i < m_objects.size(); i++)
    {
        m_objects[i]->m_collisionNormal = glm::vec3(0,0,0);

        if(m_objects[i]->isPhysicsActive())
            m_objects[i]->addImpulse(Game::GetInstance()->gravity);

        N.x = 0; N.y = 0; N.z = 0;
        t = 0.0f;

        if(m_objects[i]->isCollisionActive())
        for(unsigned long j = 0; j < m_objects.size(); j++)
        {
            if(i==j || m_objects[j]->isCollisionActive() == false) continue;

            ret = m_objects[i]->collide(m_objects[j],N,t);
            /*if(ret && t < 0 && m_objects[i]->isPhysicsActive())
                cout << N.x << " / " << N.y << " / " << N.z << endl;*/
            if(ret && t < 0 && m_objects[i]->isPhysicsActive())
            {
                //cout << "FLOOR" << endl;
                m_objects[i]->m_collisionNormal = N;

                if(N.y != 0)
                {
                    glm::vec3 floorResp = glm::vec3(0,-m_objects[i]->m_force.y, 0);
                    m_objects[i]->addImpulse(floorResp);
                    ApplyLinearCollisionImpulse(m_objects[i], 0.3);
                }
                if(N.x != 0 || N.z != 0)
                {
                    m_objects[i]->m_externalForce = -m_objects[i]->m_externalForce;

                    if(N.x != 0)
                        m_objects[i]->m_speed.x = -m_objects[i]->m_speed.x;
                    if(N.z != 0)
                        m_objects[i]->m_speed.z = -m_objects[i]->m_speed.z;
                }

            }
        }

        if(m_objects[i]->getTag() == "LIGHT")
        {
            lightMatrix = m_objects[i]->getTransform()->Matrix;
            lightPos = m_objects[i]->getTransform()->Position;
        }
    }

    for(unsigned long update = 0; update < m_objects.size(); update++)
    {
        m_objects[update]->Update();
    }

    Shader* shad = Engine::GetInstance()->getShader();
    Shader* lightShad = Engine::GetInstance()->getLightShader();

    glUniformMatrix4fv(glGetUniformLocation(lightShad->ID, "model"), 1, GL_FALSE, glm::value_ptr(lightMatrix));
	glUniform3f(glGetUniformLocation(shad->ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

}

void World::display()
{
    //Shader* shad = Engine::GetInstance()->getShader();
    Shader* transp = Engine::GetInstance()->getTransparancyShader();
    Shader* lightShad = Engine::GetInstance()->getLightShader();
    Camera* cam = Engine::GetInstance()->getCamera();

    for(unsigned long i = 0; i < m_objects.size(); i++)
    {
        if(m_objects[i]->getTag() == "BLOCK")
            m_objects[i]->Draw(transp,cam);
        //if(m_objects[i]->getTag() == "PLAYER0")
         //  m_objects[i]->Draw(transp,cam);
        if(m_objects[i]->getTag() == "BLOCK_TRANSP")
            m_objects[i]->Draw(transp,cam);
        if(m_objects[i]->getTag() == "LIGHT")
            m_objects[i]->Draw(lightShad,cam);
    }

    //delete shad; delete transp; delete lightShad; delete cam;

}

void World::Clear()
{
    for(unsigned long i = 0; i < m_objects.size(); i++)
    {
        if(m_objects[i] != nullptr)
        {
            m_objects[i]->Clear();
            delete m_objects[i];
        }
    }
}
