#pragma once

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
	class DLLExports VertexBuffer {
	private:
		GLuint vbo;
	public:
		VertexBuffer();

		void init();

		void bind(GLenum target);
		static void unbind(GLenum target);

		GLuint getVBO();

		~VertexBuffer();
	};
}