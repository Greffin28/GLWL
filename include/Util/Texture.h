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
	class DLLExports Texture {
	private:
		unsigned int tex;

		unsigned int minFilter;
		unsigned int magFilter;
		unsigned int warpS;
		unsigned int warpT;
	public:
		Texture();

		void init();

		void blankTexture(int width, int height);
		void setImage2D(Image image);

		void bind();
		static void unbind();

		void setMinFilter(unsigned int mode);
		void setMagFilter(unsigned int mode);
		void setWarpS(unsigned int mode);
		void setWarpT(unsigned int mode);

		unsigned int getID();
		
		~Texture();
	};
}