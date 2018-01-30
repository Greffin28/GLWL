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
	class Image;
	class DLLExports Texture {
	private:
		GLuint tex;

		GLenum minFilter;
		GLenum magFilter;
		GLenum warpS;
		GLenum warpT;
	public:
		Texture();

		void init();

		void blankTexture(int width, int height);
		void setImage2D(Image image);

		void bind();
		static void unbind();

		void setMinFilter(GLenum mode);
		void setMagFilter(GLenum mode);
		void setWarpS(GLenum mode);
		void setWarpT(GLenum mode);
		
		~Texture();
	};
}