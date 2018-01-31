#include "Math/Quat.h"

namespace glwl {

	Quat::Quat(float scalar, Vector3 & vector) : scalar(scalar), vector(vector) {}

	Quat::Quat(float scalar, float x, float y, float z) : Quat(scalar, Vector3(x, y, z)) {}

	void Quat::setScalar(float scalar) {
		this->scalar = scalar;
	}

	void Quat::setVector(Vector3 & vector) {
		this->vector = vector;
	}

	void Quat::setVector(float x, float y, float z) {
		setVector(Vector3(x, y, z));
	}

	float Quat::getScalar() {
		return scalar;
	}

	Vector3 Quat::getVector() {
		return vector;
	}

	Quat Quat::getStar() {
		return Quat(scalar, -vector);
	}

	Quat Quat::operator+() {
		return *this;
	}

	Quat Quat::operator-() {
		return Quat(-scalar, -vector);
	}

	Quat & Quat::operator+=(Quat & rquat) {
		scalar += rquat.scalar;
		vector += rquat.vector;
		return *this;
	}

	Quat & Quat::operator-=(Quat & rquat) {
		scalar -= rquat.scalar;
		vector -= rquat.vector;
		return *this;
	}

	Quat & Quat::operator*=(Quat & rquat) {
		return (*this = Quat(
			scalar * rquat.scalar - Vector3::dot(vector, rquat.vector),
			scalar * rquat.vector + rquat.scalar * vector + Vector3::cross(vector, rquat.vector)
		));
	}

	Quat Quat::operator+(Quat & rquat) {
		Quat result = *this;

		return (*this += rquat);
	}

	Quat Quat::operator-(Quat & rquat) {
		Quat result = *this;

		return (*this -= rquat);
	}

	Quat Quat::operator*(Quat & rquat) {
		Quat result = *this;

		return (*this *= rquat);
	}

}