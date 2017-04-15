#ifndef _GLWL_MAT4_H_
#define _GLWL_MAT4_H_

#ifdef _WIN32
	#ifdef GLWL_EXPORTS
	#define DLLExports __declspec(dllexport)
	#else
	#define DLLExports __declspec(dllimport)
	#endif
#else
#define DLLExports
#endif

#include <cmath>

#define PI 3.1415926535f

namespace glwl {
	class Vector4;
	class Matrix4 {
	private:
		float values[16];
	public:
		DLLExports Matrix4();

		DLLExports static Matrix4 identity();
		DLLExports static Matrix4 translate(float x, float y, float z);
		DLLExports static Matrix4 scale(float x, float y, float z);
		DLLExports static Matrix4 rotation(char axis, float angle);
		DLLExports static Matrix4 ortho(float l, float t, float r, float b, float n, float f);
		DLLExports static Matrix4 perspective(int width, int height, float fov, float n, float f);

		DLLExports void setValue(int i, float val);
		DLLExports float getValue(int i);
		DLLExports float * getData();

		DLLExports mat4 operator*(Matrix4 &rmat);
		DLLExports mat4 operator*=(Matrix4 &rmat);
		DLLExports vec4 operator*(Vector4 &rvec);
	};
}

#endif
