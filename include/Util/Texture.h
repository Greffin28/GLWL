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

namespace glwl {
	class Image;
	class Texture {
	private:
		unsigned int tex;

		unsigned int minFilter;
		unsigned int magFilter;
		unsigned int warpS;
		unsigned int warpT;
	public:
		DLLExports Texture();

		DLLExports void init();

		DLLExports void blankTexture(int width, int height);
		DLLExports void setImage2D(Image image);

		DLLExports void bind();
		DLLExports void unbind();

		DLLExports void setMinFilter(unsigned int mode);
		DLLExports void setMagFilter(unsigned int mode);
		DLLExports void setWarpS(unsigned int mode);
		DLLExports void setWarpT(unsigned int mode);

		DLLExports unsigned int getID();
		
		DLLExports ~Texture();
	};
}