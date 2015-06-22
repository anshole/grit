#include "Mesh.h"

namespace grit {

Mesh::Mesh(std::vector<float> vertices, std::vector<int> indices) {
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 1, GL_UNSIGNED_INT, GL_FALSE, 0, (GLvoid *)0);
}


void Mesh::dispose() {
	Utils::log("Disposing mesh.");
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &elementBuffer);
	glDeleteVertexArrays(1, &vaoID);
}

void Mesh::render() {
	glBindVertexArray(vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid *) 0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

}