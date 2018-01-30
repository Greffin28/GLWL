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
	class FrameBuffer {
	private:
		GLuint fbo;
		Texture tex;
		GLuint rbo;
	public:
		DLLExports FrameBuffer();

		DLLExports void init();

		DLLExports void setUp(int width, int height, bool depth = false);

		DLLExports void bind();
		DLLExports static void unbind();

		DLLExports GLuint getFBO();

		DLLExports ~FrameBuffer();
	};
}