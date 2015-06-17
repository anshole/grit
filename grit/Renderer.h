#pragma once

#include <GL\glew.h>
#include <string>
#include "ShaderProgram.h"
#include "Mesh.h"

namespace grit {

	class ShaderProgram;

class Renderer
{
public:
	~Renderer();

	void initShaders(std::string vertexShaderFile, std::string fragmentShaderFile);
	void render();

	static std::vector<Mesh> meshes;
	GLuint programID;
private:
	ShaderProgram shaderProgram;
};

}