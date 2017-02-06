#include "util\vertex_buffer.h"

namespace glwl {
	VertexBuffer::VertexBuffer() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
	}

	void VertexBuffer::bindVAO() {
		glBindVertexArray(vao);
	}

	void VertexBuffer::bindVBO(GLenum target) {
		glBindBuffer(target, vbo);
	}

	void VertexBuffer::unbindVAO() {
		glBindVertexArray(0);
	}

	void VertexBuffer::unbindVBO(GLenum target) {
		glBindBuffer(target, 0);
	}

	GLuint VertexBuffer::getVAO() {
		return vao;
	}

	GLuint VertexBuffer::getVBO() {
		return vbo;
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}
}