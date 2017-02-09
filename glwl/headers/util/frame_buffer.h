#ifndef _GLWL_FRAME_BUFFER_H_
#define _GLWL_FRAME_BUFFER_H_

#ifdef GLWL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

namespace glwl {
	class FrameBuffer {
	private:
		GLuint fbo;
	public:
		DLLExports FrameBuffer();

		DLLExports void bind();
		DLLExports static void unbind();

		DLLExports ~FrameBuffer();
	};
}

#endif