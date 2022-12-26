#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include <iostream>

#include "vao.h"
#include "ebo.h"
#include "camera.h"
#include "texture.h"


struct Transform
{
    glm::mat4 Matrix = glm::mat4(1.0f);
	glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::quat Rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

	Transform(){}
	~Transform(){}
	void Translate(float x, float y, float z);
	void reScale(float x, float y, float z);
	void setNewPos(glm::vec3 newPos){Position = newPos;}

};

class Mesh
{
    public:
       std::vector<Vertex> vertices;
       std::vector<GLuint> indices;
       std::vector<Texture> textures;

       VAO VAO;
       Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);
       ~Mesh(){}
       void Draw
        (
        Shader& shader,
        Camera& camera,
        Transform* mTransform
        );


};



#endif // MESH_H


