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
	class DLLExports VertexArray {
	private:
		unsigned int vao;
	public:
		VertexArray();
		
		void init();

		void setVertexAttrib(Shader & shader, const char * varName, int count, unsigned int glVarType, int stride, int offset);

		void bind();
		void unbind();
		
		unsigned int getVAO();
		
		~VertexArray();
	};
}