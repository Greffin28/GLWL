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
		unsigned int targetType;
	public:
		VertexBuffer();
		
		void init(unsigned int target);

		void setData(int byteSize, const void * dataPtr, unsigned int glDrawMethod);

		void bind();
		void unbind();

		unsigned int getVBO();

		~VertexBuffer();
	};
}