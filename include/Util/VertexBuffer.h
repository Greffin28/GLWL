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
	class VertexBuffer {
	public:
		DLLExports VertexBuffer();
		DLLExports ~VertexBuffer();
		
		DLLExports void init(unsigned int target);

		DLLExports void setData(int byteSize, const void * dataPtr, unsigned int glDrawMethod);

		DLLExports void bind();
		DLLExports void unbind();

		DLLExports unsigned int getVBO() const;
	private:
		unsigned int vbo;
		unsigned int targetType;
	};
}