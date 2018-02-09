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
	class Vector3 {
	private:
		float values[3];
	public:
		DLLExports Vector3() {};
		DLLExports Vector3(float f);
		DLLExports Vector3(float x, float y, float z);

		DLLExports static float dot(Vector3 & lvec, Vector3 & rvec);
		DLLExports static Vector3 cross(Vector3 & lvec, Vector3 & rvec);

		DLLExports Vector3 & normalize();

		DLLExports void setX(float x);
		DLLExports void setY(float y);
		DLLExports void setZ(float z);
		DLLExports void setVec(float x, float y, float z);

		DLLExports float getX();
		DLLExports float getY();
		DLLExports float getZ();
		DLLExports float * getData();
		DLLExports float getLength();
		DLLExports Vector3 getNormalize();

		DLLExports Vector3 operator+();
		DLLExports Vector3 operator-();

		DLLExports Vector3 & operator+=(Vector3 & rvec);
		DLLExports Vector3 & operator-=(Vector3 & rvec);
		DLLExports Vector3 & operator*=(float f);

		DLLExports Vector3 operator+(Vector3 & rvec);
		DLLExports Vector3 operator-(Vector3 & rvec);
		DLLExports Vector3 operator*(float f);

		DLLExports friend Vector3 operator*(float f, Vector3 & rvec);
	};

	DLLExports Vector3 operator*(float f, Vector3 & rvec);
}