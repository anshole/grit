#include "ShaderProgram.h"

namespace grit {

std::string ShaderProgram::readFile(const char *filePath) {
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "[Fatal Error] Failed to read file: " << filePath << std::endl;
		std::exit(1);
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}

GLuint ShaderProgram::loadShaders(const char * vertexpath, const char * fragmentpath) {
	std::string vertexShader = readFile("vertex_shader.txt");
	std::string fragmentShader = readFile("fragment_shader.txt");
	const char *vertexShaderSource = vertexShader.c_str();
	const char *fragmentShaderSource = fragmentShader.c_str();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShaderSource, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShaderSource, NULL);
	glCompileShader(fs);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fs);
	glAttachShader(shaderProgram, vs);
	glLinkProgram(shaderProgram);

	return shaderProgram;
}

}