#include "Window.h"

namespace grit 
{

Window::Window(int width, int height, std::string title) {

	if (glfwInit() == GL_FALSE) {
		printf("Could not initialise GLFW\n");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	makeCurrent();

	glewExperimental = GL_TRUE;
	glewInit();

	renderer.initShaders("vertex_shader.txt", "fragment_shader.txt");
}

void Window::makeCurrent() {
	glfwMakeContextCurrent(window);
}

void Window::update() {

	Utils::log("Updating window.");

	while (!shouldClose()) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.34f, 0, 0, 1);

		renderer.render();

		glfwSwapBuffers(window);
	}

	close();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::close() {
	glfwTerminate();
}

}