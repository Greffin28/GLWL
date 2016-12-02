#ifndef _GOGLL_VERTEX_BUFFER_H_
#define _GOGLL_VERTEX_BUFFER_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

namespace gogll {
	class VertexBuffer {
	private:
		GLuint vbo, vao;
	public:
		DLLExports VertexBuffer();

		DLLExports ~VertexBuffer();
	};
}

#endif