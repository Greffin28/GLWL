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
	class DLLExports Matrix4 {
	private:
		float values[16];
	public:
		Matrix4();
		Matrix4(float * values);

		static Matrix4 identity();
		static Matrix4 translate(float x, float y, float z);
		static Matrix4 scale(float x, float y, float z);
		static Matrix4 rotation(char axis, float angle);
		static Matrix4 ortho(float l, float t, float r, float b, float n, float f);
		static Matrix4 perspective(int width, int height, float fov, float n, float f);

		Matrix4 & transpose();

		void setValue(int i, float val);
		void setValue(int x, int y, float val);
		void setValues(float * values);

		float getValue(int i);
		float getValue(int x, int y);
		float * getData();
		Matrix4 getTranspose();

		Matrix4 operator+();
		Matrix4 operator-();

		Matrix4 operator+(Matrix4 & rmat);
		Matrix4 operator-(Matrix4 & rmat);
		Matrix4 operator*(Matrix4 & rmat);
		Matrix4 operator*(float value);

		Matrix4 & operator+=(Matrix4 & rmat);
		Matrix4 & operator-=(Matrix4 & rmat);
		Matrix4 & operator*=(Matrix4 & rmat);
		Matrix4 & operator*=(float value);

		Vector4 operator*(Vector4 & rvec);

		DLLExports friend Matrix4 operator*(float value, Matrix4 & rmat);
	};

	DLLExports Matrix4 operator*(float value, Matrix4 & rmat);

}