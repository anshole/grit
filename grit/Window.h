#pragma once

#include <stdio.h>
#include <string>
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include "Utils.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Renderer.h"

namespace grit {

class Window
{
public:
	Window(int width, int height, std::string title);

	void makeCurrent();
	void update();
	
	GLFWwindow* window;

	bool shouldClose();
	void close();
private:
	int width;
	int height;
	Renderer renderer;
};

}