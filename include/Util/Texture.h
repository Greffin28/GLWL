#ifndef _GLWL_TEXTURE_H_
#define _GLWL_TEXTURE_H_

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
	class Image;
	class Texture {
	private:
		GLuint tex;

		GLenum minFilter;
		GLenum magFilter;
		GLenum warpS;
		GLenum warpT;
	public:
		DLLExports Texture();

		DLLExports void init();

		DLLExports void blankTexture(int width, int height);
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
