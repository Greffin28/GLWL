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

namespace glwl {
	class Shader {
	public:
		DLLExports ~Shader();

		DLLExports void loadvf(const char * vPath, const char * fPath);
		DLLExports void compilevf();
		DLLExports void setProgramvf();

		DLLExports void useProgram();
		DLLExports void unuseProgram();

		DLLExports unsigned int getProgram() const;
	private:
		unsigned int program, vShader, fShader;

		std::string vSource, fSource;
		const char *glvSource, *glfSource;
	};
}