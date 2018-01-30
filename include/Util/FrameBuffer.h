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

#include "Util/Texture.h"

namespace glwl {
	class DLLExports FrameBuffer {
	private:
		GLuint fbo;
		Texture tex;
		GLuint rbo;
	public:
		FrameBuffer();

		void init();

		void setUp(int width, int height, bool depth = false);

		void bind();
		static void unbind();

		GLuint getFBO();

		~FrameBuffer();
	};
}