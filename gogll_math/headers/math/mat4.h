#ifndef _GOGLL_MAT4_H_
#define _GOGLL_MAT4_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <cmath>

#define PI 3.1415926535f

namespace gogll {
	class vec4;
	class mat4 {
	private:
		float values[16];
	public:
		DLLExports mat4();

		DLLExports static mat4 identity();
		DLLExports static mat4 translate(float x, float y, float z);
		DLLExports static mat4 rotation(char axis, float angle);
		DLLExports static mat4 ortho(float l, float t, float r, float b, float n, float f);
		DLLExports static mat4 perspective(int width, int height, float fov, float n, float f);

		DLLExports void setValue(int i, float val);
		DLLExports float getValue(int i);
		DLLExports float * getData();

		DLLExports mat4 operator*(mat4 &lmat);
		DLLExports void operator*=(mat4 &lmat);
		DLLExports vec4 operator*(vec4 &lmat);
	};
}

#endif