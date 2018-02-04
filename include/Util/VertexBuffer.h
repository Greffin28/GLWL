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
	class DLLExports VertexBuffer {
	private:
		unsigned int vbo;
	public:
		VertexBuffer();
		
		void init();

		void bind(unsigned int target);
		static void unbind(unsigned int target);

		unsigned int getVBO();

		~VertexBuffer();
	};
}