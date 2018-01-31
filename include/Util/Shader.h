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

#include <string>

#include <GL/glew.h>

namespace glwl {
	class DLLExports Shader {
	private:
		GLuint program, vShader, fShader;

		std::string vSource, fSource;
		const GLchar *glvSource, *glfSource;
	public:
		void loadvf(std::string vPath, std::string fPath);
		void compilevf();
		void setProgramvf();

		void useProgram();
		static void unuseProgram();

		GLuint getProgram();

		~Shader();
	};
}