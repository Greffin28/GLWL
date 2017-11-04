#ifndef _GLWL_VERTEX_ARRAY_H_
#define _GLWL_VERTEX_ARRAY_H_

#ifdef _WIN32
	#ifdef GLWL_EXPORTS
	#define DLLExports __declspec(dllexport)
	#else
	#define DLLExports __declspec(dllimport)
	#endif
#else
#define DLLExports
#endif

#include <GL/glew.h>

namespace glwl {
	class VertexArray {
	private:
		GLuint vao;
	public:
		DLLExports VertexArray();
		
		DLLExports void init();

		DLLExports void bind();
		DLLExports static void unbind();
		
		DLLExports GLuint getVAO();
		
		DLLExports ~VertexArray();
	};
}

#endif
