#ifndef SHADERS_H_INCLUDED
#define SHADERS_H_INCLUDED

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
    GLuint ID;
    Shader(const char* vertexFile, const char* fragmentFile);
    ~Shader(){}

    void Activate();
    void Delete();

private:
	// Checks if the different Shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
};

#endif // SHADERS_H_INCLUDED
