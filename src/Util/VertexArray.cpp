#include <Util/VertexArray.h>

#include <GL/glew.h>

namespace glwl {

	VertexArray::VertexArray() {
		
	}

	void VertexArray::init() {
		glGenVertexArrays(1, &vao);
	}

	void VertexArray::bind() {
		glBindVertexArray(vao);
	}

	void VertexArray::unbind() {
		glBindVertexArray(0);
	}

	unsigned int VertexArray::getVAO() {
		return vao;
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &vao);
	}

}
