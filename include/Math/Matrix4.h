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

#define PI 3.1415926535f

namespace glwl {
	class Vector4;
	class Matrix4 {
	public:
		DLLExports Matrix4();
		DLLExports Matrix4(float * values);

		DLLExports static Matrix4 identity();
		DLLExports static Matrix4 translate(float x, float y, float z);
		DLLExports static Matrix4 scale(float x, float y, float z);
		DLLExports static Matrix4 rotation(char axis, float angle);
		DLLExports static Matrix4 ortho(float l, float t, float r, float b, float n, float f);
		DLLExports static Matrix4 perspective(int width, int height, float fov, float n, float f);

		DLLExports Matrix4 & transpose();

		DLLExports void setValue(int i, float val);
		DLLExports void setValue(int x, int y, float val);
		DLLExports void setValues(float * values);

		DLLExports float getValue(int i) const;
		DLLExports float getValue(int x, int y) const;
		DLLExports const float * getData() const;
		DLLExports Matrix4 getTranspose() const;

		DLLExports Matrix4 operator+() const;
		DLLExports Matrix4 operator-() const;

		DLLExports Matrix4 & operator+=(const Matrix4 & rmat);
		DLLExports Matrix4 & operator-=(const Matrix4 & rmat);
		DLLExports Matrix4 & operator*=(const Matrix4 & rmat);
		DLLExports Matrix4 & operator*=(float value);

		DLLExports Matrix4 operator+(const Matrix4 & rmat) const;
		DLLExports Matrix4 operator-(const Matrix4 & rmat) const;
		DLLExports Matrix4 operator*(const Matrix4 & rmat) const;
		DLLExports Matrix4 operator*(float value) const;

		DLLExports Vector4 operator*(const Vector4 & rvec) const;

		DLLExports friend Matrix4 operator*(float value, const Matrix4 & rmat);
	private:
		float values[16];
	};

	DLLExports Matrix4 operator*(float value, const Matrix4 & rmat);

}