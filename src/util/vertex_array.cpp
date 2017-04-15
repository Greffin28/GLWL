#include <util/vertex_array.h>

namespace glwl {

	VertexArray::VertexArray() {
		glGenVertexArrays(1, &vao);
	}

	void VertexArray::bind() {
		glBindVertexArray(vao);
	}

	void VertexArray::unbind() {
		glBindVertexArray(0);
	}

	GLuint VertexArray::getVAO() {
		return vao;
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &vao);
	}

}
