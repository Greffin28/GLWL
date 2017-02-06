#ifndef _GOGLL_TEXTURE_H_
#define _GOGLL_TEXTURE_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <GL\glew.h>

#include "image.h"

namespace glwl {
	class Texture {
	private:
		GLuint tex;

		GLenum minFilter;
		GLenum magFilter;
		GLenum warpS;
		GLenum warpT;
	public:
		DLLExports Texture();

		DLLExports void setImage2D(Image image);

		DLLExports void bind();
		DLLExports static void unbind();

		DLLExports void setMinFilter(GLenum mode);
		DLLExports void setMagFilter(GLenum mode);
		DLLExports void setWarpS(GLenum mode);
		DLLExports void setWarpT(GLenum mode);
		DLLExports GLuint getID();

		DLLExports ~Texture();
	};
}

#endif