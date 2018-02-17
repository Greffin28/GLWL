#pragma once

#ifdef _WIN32
#	ifdef GLWL_EXPORTS
#		define DLLExports __declspec(dllexport)
#	else
#		define DLLExports __declspec(dllimport)
#	endif
#else
#	define DLLExports
#endif

#include "Util/Texture.h"

namespace glwl {
	class FrameBuffer {
	public:
		DLLExports FrameBuffer();
		DLLExports ~FrameBuffer();

		DLLExports void init();

		DLLExports void setUp(int width, int height, bool depth = false);

		DLLExports void bind();
		DLLExports void unbind();

		DLLExports unsigned int getFBO();
	private:
		unsigned int fbo;
		Texture tex;
		unsigned int rbo;
	};
}