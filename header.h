#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <time.h>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <math.h>
#include <fstream>
#include <sstream>


using namespace std;

void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;




#endif // HEADER_H_INCLUDED
