#include "Util/VertexBuffer.h"

#include <GL/glew.h>

namespace glwl {

	VertexBuffer::VertexBuffer() {
		
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &vbo);
	}

	void VertexBuffer::init(unsigned int target) {
		glGenBuffers(1, &vbo);
		targetType = target;
	}

	void VertexBuffer::setData(int byteSize, const void * dataPtr, unsigned int glDrawMethod) {
		glBufferData(targetType, byteSize, dataPtr, glDrawMethod);
	}

	void VertexBuffer::bind() {
		glBindBuffer(targetType, vbo);
	}

	void VertexBuffer::unbind() {
		glBindBuffer(targetType, 0);
	}

	unsigned int VertexBuffer::getVBO() const {
		return vbo;
	}

}
