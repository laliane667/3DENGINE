#include "mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
{
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    Mesh::textures = textures;

    VAO.Bind();

    VBO VBO(vertices);
    EBO EBO(indices);

    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3* sizeof(float)));
    VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6* sizeof(float)));
    VAO.LinkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9* sizeof(float)));

    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();

    /*int cnt = 0;
    float x, y, z;
    for(unsigned long t = 0; t < 24; t++)
    {
        for(unsigned long u = 0; u < 3; u++)
            cnt++;

        for(unsigned long u = 0; u < 3; u++)
        {
            switch(u)
            {
                case 0: x = vertices[cnt]; break;
                case 1: y = vertices[cnt]; break;
                case 2: z = vertices[cnt]; break;
            }
            cnt++;
        }
        normals.push_back(glm::vec3 = glm::vec3(x, y, z));


        for(unsigned long u = 0; u < 3; u++)
            cnt++;

        for(unsigned long u = 0; u < 2; u++)
            cnt++;

    }*/
}

void Transform::reScale(float x, float y, float z)
{
    Matrix = glm::scale(Matrix, glm::vec3(x, y, z));
    // = myMatrix * ;
    /*Scale.x += x;
    Scale.y += y;
    Scale.z += z;*/
}

void Transform::Translate(float x, float y, float z)
{
    glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(x, y, z));
    Matrix = myMatrix * Matrix;
    Position.x += x;
    Position.y += y;
    Position.z += z;
}

void Mesh::Draw
(
	Shader& shader,
	Camera& camera,
	Transform* mTransform
)
{
    glm::mat4 matrix = glm::mat4(1.0f);
    glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

    if(mTransform != nullptr)
    {
        matrix = mTransform->Matrix;
        rotation = mTransform->Rotation;
        scale = mTransform->Scale;
    }

	// Bind shader to be able to access uniforms
	shader.Activate();
	VAO.Bind();

	// Keep track of how many of each type of textures we have
	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		std::string type = textures[i].type;
		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if (type == "specular")
		{
			num = std::to_string(numSpecular++);
		}
		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}
	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Initialize matrices
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 sca = glm::mat4(1.0f);

	// Transform the matrices to their correct form
	trans = glm::translate(trans, translation);
	rot = glm::mat4_cast(rotation);
	sca = glm::scale(sca, scale);


    //rot = glm::rotate(rot, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	// Push the matrices to the vertex shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "translation"), 1, GL_FALSE, glm::value_ptr(trans));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "rotation"), 1, GL_FALSE, glm::value_ptr(rot));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "scale"), 1, GL_FALSE, glm::value_ptr(sca));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(matrix));

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

