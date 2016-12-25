#ifndef _GOGLL_TEXTURE_H_
#define _GOGLL_TEXTURE_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

namespace gogll {
	class Texture {
	private:
		GLuint tex;
	public:
		DLLExports Texture();

		DLLExports void bind();
		DLLExports static void unbind();

		DLLExports ~Texture();
	};
}

#endif