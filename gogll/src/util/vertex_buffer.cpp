#include "util\vertex_buffer.h"

namespace gogll {
	VertexBuffer::VertexBuffer() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}
}