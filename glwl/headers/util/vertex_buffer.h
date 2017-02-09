#ifndef _GLWL_VERTEX_BUFFER_H_
#define _GLWL_VERTEX_BUFFER_H_

#ifdef GLWL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

namespace glwl {
	class VertexBuffer {
	private:
		GLuint vbo;
	public:
		DLLExports VertexBuffer();

		DLLExports void bind(GLenum target);
		DLLExports static void unbind(GLenum target);

		DLLExports GLuint getVBO();

		DLLExports ~VertexBuffer();
	};
}

#endif