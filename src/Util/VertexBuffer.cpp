#include "Util/VertexBuffer.h"

namespace glwl {

	VertexBuffer::VertexBuffer() {
		glGenBuffers(1, &vbo);
	}

	void VertexBuffer::bind(GLenum target) {
		glBindBuffer(target, vbo);
	}

	void VertexBuffer::unbind(GLenum target) {
		glBindBuffer(target, 0);
	}

	GLuint VertexBuffer::getVBO() {
		return vbo;
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &vbo);
	}

}
