#ifndef _GOGLL_VERTEX_BUFFER_H_
#define _GOGLL_VERTEX_BUFFER_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

namespace glwl {
	class VertexBuffer {
	private:
		GLuint vbo, vao;
	public:
		DLLExports VertexBuffer();

		DLLExports void bindVAO();
		DLLExports void bindVBO(GLenum target);
		DLLExports static void unbindVAO();
		DLLExports static void unbindVBO(GLenum target);

		DLLExports GLuint getVAO();
		DLLExports GLuint getVBO();

		DLLExports ~VertexBuffer();
	};
}

#endif