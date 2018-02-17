#include "Util/VertexArray.h"

#include <GL/glew.h>

#include "Util/Shader.h"

namespace glwl {

	VertexArray::VertexArray() {
		
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &vao);
	}

	void VertexArray::init() {
		glGenVertexArrays(1, &vao);
	}

	void VertexArray::setVertexAttrib(Shader & shader, const char * varName, int count, unsigned int glVarType, int stride, int offset) {
		int varLoc = glGetAttribLocation(shader.getProgram(), varName);
		glVertexAttribPointer(varLoc, count, glVarType, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(varLoc);
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

}
