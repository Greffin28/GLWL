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
	class Shader;
	class VertexArray {
	private:
		unsigned int vao;
	public:
		DLLExports VertexArray();
		
		DLLExports void init();

		DLLExports void setVertexAttrib(Shader & shader, const char * varName, int count, unsigned int glVarType, int stride, int offset);

		DLLExports void bind();
		DLLExports void unbind();
		
		DLLExports unsigned int getVAO();
		
		DLLExports ~VertexArray();
	};
}