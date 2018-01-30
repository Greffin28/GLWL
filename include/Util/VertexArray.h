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
	class DLLExports VertexArray {
	private:
		GLuint vao;
	public:
		VertexArray();
		
		void init();

		void bind();
		static void unbind();
		
		GLuint getVAO();
		
		~VertexArray();
	};
}