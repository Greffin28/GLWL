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
	class DLLExports FrameBuffer {
	private:
		unsigned int fbo;
		Texture tex;
		unsigned int rbo;
	public:
		FrameBuffer();

		void init();

		void setUp(int width, int height, bool depth = false);

		void bind();
		static void unbind();

		unsigned int getFBO();

		~FrameBuffer();
	};
}