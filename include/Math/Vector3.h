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
	public:
		DLLExports Vector3() {};
		DLLExports Vector3(float f);
		DLLExports Vector3(float x, float y, float z);

		DLLExports static float dot(const Vector3 & lvec, const Vector3 & rvec);
		DLLExports static Vector3 cross(const Vector3 & lvec, const Vector3 & rvec);

		DLLExports Vector3 & normalize();

		DLLExports void setX(float x);
		DLLExports void setY(float y);
		DLLExports void setZ(float z);
		DLLExports void setVec(float x, float y, float z);

		DLLExports float getX() const;
		DLLExports float getY() const;
		DLLExports float getZ() const;
		DLLExports const float * getData() const;
		DLLExports float getLength() const;
		DLLExports Vector3 getNormalize() const;

		DLLExports Vector3 operator+() const;
		DLLExports Vector3 operator-() const;

		DLLExports Vector3 & operator+=(const Vector3 & rvec);
		DLLExports Vector3 & operator-=(const Vector3 & rvec);
		DLLExports Vector3 & operator*=(float f);

		DLLExports Vector3 operator+(const Vector3 & rvec) const;
		DLLExports Vector3 operator-(const Vector3 & rvec) const;
		DLLExports Vector3 operator*(float f) const;

		DLLExports friend Vector3 operator*(float f, const Vector3 & rvec);
	private:
		float values[3];
	};

	DLLExports Vector3 operator*(float f, const Vector3 & rvec);
}