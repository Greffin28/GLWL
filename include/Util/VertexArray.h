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
	class DLLExports VertexArray {
	private:
		unsigned int vao;
	public:
		VertexArray();
		
		void init();

		void bind();
		static void unbind();
		
		unsigned int getVAO();
		
		~VertexArray();
	};
}