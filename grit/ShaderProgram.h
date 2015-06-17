#pragma once

#include <string>
#include <GL\glew.h>
#include <fstream>
#include <iostream>

namespace grit {

class ShaderProgram
{
public:
	GLuint loadShaders(const char * vertexpath, const char * fragmentpath);
private:
	std::string readFile(const char *filePath);
};

}