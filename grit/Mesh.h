#pragma once

#include <GL\glew.h>
#include <vector>
#include "Utils.h"

namespace grit {

class Mesh
{
public:
	Mesh(std::vector<float> vertices, std::vector<int> indices);

	void render();
	void dispose();

	GLuint vertexBuffer;
	GLuint elementBuffer;
private:
	GLuint textureID;
	GLuint vaoID = 0;
};

}