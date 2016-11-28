#ifndef _GOGLL_SHADER_H_
#define _GOGLL_SHADER_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <fstream>

#include <GL\glew.h>

namespace gogll {
	class Shader {
	private:
		int program, vShader, fShader;

		std::string vSource, fSource;
		const GLchar *glvSource, *glfSource;
	public:
		DLLExports void loadvf(std::string vPath, std::string fPath);
		DLLExports void compilevf();
	};
}

#endif