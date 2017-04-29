#ifndef _GOGLL_VEC4_H_
#define _GOGLL_VEC4_H_

#ifdef _WIN32
	#ifdef GLWL_EXPORTS
	#define DLLExports __declspec(dllexport)
	#else
	#define DLLExports __declspec(dllimport)
	#endif
#else
#define DLLExports
#endif

#include <Math/Matrix4.h>

namespace glwl {
	class Vector4 {
	private:
		float values[4];
	public:
		DLLExports Vector4() {};
		DLLExports Vector4(float f);
		DLLExports Vector4(float x, float y, float z, float w = 1.0f);

		DLLExports void setValue(int i, float val);
		DLLExports float getValue(int i) const;
		DLLExports float * getData();

		DLLExports static float dot(Vector4 & lvec, Vector4 & rvec);
	};
}

#endif
