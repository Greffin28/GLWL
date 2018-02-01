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
	class DLLExports Quat {
	private:
		float scalar;
		Vector3 vector;
	public:
		Quat() {};
		Quat(float scalar, Vector3 & vector);
		Quat(float scalar, float x, float y, float z);
		Quat(Vector3 & axis, float angle);
		Quat(Vector3 & angles);

		void setScalar(float scalar);
		void setVector(Vector3 & vector);
		void setVector(float x, float y, float z);

		float getScalar();
		Vector3 getVector();
		Quat getStar();
		Matrix4 getMatrix();

		Quat operator+();
		Quat operator-();

		Quat & operator+=(Quat & rquat);
		Quat & operator-=(Quat & rquat);
		Quat & operator*=(Quat & rquat);

		Quat operator+(Quat & rquat);
		Quat operator-(Quat & rquat);
		Quat operator*(Quat & rquat);
	};
}