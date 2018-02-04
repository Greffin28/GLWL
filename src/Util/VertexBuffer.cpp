#include "Util/VertexBuffer.h"

#include <GL/glew.h>

namespace glwl {

	VertexBuffer::VertexBuffer() {
		
	}

	void VertexBuffer::init() {
		glGenBuffers(1, &vbo);
	}

	void VertexBuffer::bind(unsigned int target) {
		glBindBuffer(target, vbo);
	}

	void VertexBuffer::unbind(unsigned int target) {
		glBindBuffer(target, 0);
	}

	unsigned int VertexBuffer::getVBO() {
		return vbo;
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &vbo);
	}

}
