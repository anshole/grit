#include <stdio.h>
#include "Window.h"
#include <vector>
#include "Mesh.h"
#include "Utils.h"
#include <Windows.h>
#include <GL\glew.h>
#include "Renderer.h"

int main() {
	
	grit::Window window(400, 400, "Grit");

	std::vector<float> vertices = { -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	std::vector<int> indices = { 0, 1, 2 };
	grit::Mesh mesh(vertices, indices);

	grit::Renderer renderer;
	renderer.meshes.push_back(mesh);

	window.update();

	return 0;
}