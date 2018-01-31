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

namespace glwl {
	class Quat {
	private:
		float scalar;
		Vector3 vector;
	public:
		Quat() {};
		Quat(float scalar, Vector3 & vector);
		Quat(float scalar, float x, float y, float z);

		void setScalar(float scalar);
		void setVector(Vector3 & vector);
		void setVector(float x, float y, float z);

		float getScalar();
		Vector3 getVector();
		Quat getStar();

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