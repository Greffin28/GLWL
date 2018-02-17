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
	class Vector4 {
	public:
		DLLExports Vector4() {};
		DLLExports Vector4(float f);
		DLLExports Vector4(float x, float y, float z, float w = 1.0f);

		DLLExports void setX(float x);
		DLLExports void setY(float y);
		DLLExports void setZ(float z);
		DLLExports void setW(float w);
		DLLExports void setValue(int i, float val);
		DLLExports void setVec(float x, float y, float z, float w = 1.0f);

		DLLExports float getX() const;
		DLLExports float getY() const;
		DLLExports float getZ() const;
		DLLExports float getW() const;
		DLLExports const float * getData() const;

		DLLExports static float dot(const Vector4 & lvec, const Vector4 & rvec);

		DLLExports Vector4 operator+() const;
		DLLExports Vector4 operator-() const;

		DLLExports Vector4 & operator+=(const Vector4 & rvec);
		DLLExports Vector4 & operator-=(const Vector4 & rvec);

		DLLExports Vector4 operator+(const Vector4 & rvec) const;
		DLLExports Vector4 operator-(const Vector4 & rvec) const;
	private:
		float values[4];
	};
}