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
	public:
		DLLExports VertexArray();
		DLLExports ~VertexArray();
		
		DLLExports void init();

		DLLExports void setVertexAttrib(const Shader & shader, const char * varName, int count, unsigned int glVarType, int stride, int offset);

		DLLExports void bind();
		DLLExports void unbind();
		
		DLLExports unsigned int getVAO() const;
	private:
		unsigned int vao;
	};
}