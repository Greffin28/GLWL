#ifndef _GLWL_FRAME_BUFFER_H_
#define _GLWL_FRAME_BUFFER_H_

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

		DLLExports void setUp(int width, int height, bool depth = false);

		DLLExports void bind();
		DLLExports static void unbind();

		DLLExports GLuint getFBO();

		DLLExports ~FrameBuffer();
	};
}

#endif
