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
	class DLLExports Vector3 {
	private:
		float values[3];
	public:
		Vector3() {};
		Vector3(float f);
		Vector3(float x, float y, float z);

		static float dot(Vector3 & lvec, Vector3 & rvec);
		static Vector3 cross(Vector3 & lvec, Vector3 & rvec);

		Vector3 & normalize();

		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setVec(float x, float y, float z);

		float getX();
		float getY();
		float getZ();
		float * getData();
		float getLength();
		Vector3 getNormalize();

		Vector3 operator+();
		Vector3 operator-();

		Vector3 & operator+=(Vector3 & rvec);
		Vector3 & operator-=(Vector3 & rvec);
		Vector3 & operator*=(float f);

		Vector3 operator+(Vector3 & rvec);
		Vector3 operator-(Vector3 & rvec);
		Vector3 operator*(float f);

		DLLExports friend Vector3 operator*(float f, Vector3 & rvec);
	};

	DLLExports Vector3 operator*(float f, Vector3 & rvec);
}