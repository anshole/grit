#include "Renderer.h"

namespace grit {

void Renderer::initShaders(std::string vertexShaderFile, std::string fragmentShaderFile) {
	programID = shaderProgram.loadShaders(vertexShaderFile.c_str(), fragmentShaderFile.c_str());
}

Renderer::~Renderer() {
}

std::vector<Mesh> Renderer::meshes;

void Renderer::render() {
	glUseProgram(programID);

	for (Mesh m : meshes) {
		m.render();
	}
}

}