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

#include "Math/Vector3.h"
#include "Math/Matrix4.h"

namespace glwl {
	class Matrix4;
	class Quat {
	private:
		float scalar;
		Vector3 vector;
	public:
		DLLExports Quat() {};
		DLLExports Quat(float scalar, Vector3 & vector);
		DLLExports Quat(float scalar, float x, float y, float z);
		DLLExports Quat(Vector3 & axis, float angle);
		DLLExports Quat(Vector3 & angles);

		DLLExports void setScalar(float scalar);
		DLLExports void setVector(Vector3 & vector);
		DLLExports void setVector(float x, float y, float z);

		DLLExports float getScalar();
		DLLExports Vector3 getVector();
		DLLExports Quat getStar();
		DLLExports Matrix4 getMatrix();

		DLLExports Quat operator+();
		DLLExports Quat operator-();

		DLLExports Quat & operator+=(Quat & rquat);
		DLLExports Quat & operator-=(Quat & rquat);
		DLLExports Quat & operator*=(Quat & rquat);

		DLLExports Quat operator+(Quat & rquat);
		DLLExports Quat operator-(Quat & rquat);
		DLLExports Quat operator*(Quat & rquat);
	};
}