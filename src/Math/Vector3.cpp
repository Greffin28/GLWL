#include "Math/Vector3.h"

namespace glwl {
	Vector3::Vector3(float f) {
		for (int i = 0; i < 3; ++i) {
			values[i] = f;
		}
	}

	Vector3::Vector3(float x, float y, float z) {
		values[0] = x;
		values[1] = y;
		values[2] = z;
	}

	float Vector3::dot(Vector3 lvec, Vector3 rvec) {
		return lvec.values[0] * rvec.values[0] +
			lvec.values[1] * rvec.values[1] +
			lvec.values[2] * rvec.values[2];
	}

	Vector3 Vector3::cross(Vector3 lvec, Vector3 rvec) {
		return Vector3(
			lvec.values[1] * rvec.values[2] - rvec.values[1] * lvec.values[2],
			lvec.values[2] * rvec.values[0] - rvec.values[2] * lvec.values[0],
			lvec.values[0] * rvec.values[1] - rvec.values[0] * lvec.values[1]
		);
	}

	void Vector3::setX(float x) {
		values[0] = x;
	}

	void Vector3::setY(float y) {
		values[1] = y;
	}

	void Vector3::setZ(float z) {
		values[2] = z;
	}

	void Vector3::setVec(float x, float y, float z) {
		*this = Vector3(x, y, z);
	}

	float Vector3::getX() {
		return values[0];
	}

	float Vector3::getY() {
		return values[1];
	}

	float Vector3::getZ() {
		return values[2];
	}

	float * Vector3::getData() {
		return values;
	}

	Vector3 Vector3::operator+() {
		return *this;
	}

	Vector3 Vector3::operator-() {
		Vector3 result = *this;

		for (int i = 0; i < 3; ++i) {
			result.values[i] = -result.values[i];
		}

		return result;
	}

	Vector3 Vector3::operator+(Vector3 & rvec) {
		Vector3 result = *this;

		return (result += rvec);
	}

	Vector3 Vector3::operator-(Vector3 & rvec) {
		Vector3 result = *this;

		return (result -= rvec);
	}

	Vector3 & Vector3::operator+=(Vector3 & rvec) {
		for (int i = 0; i < 3; ++i) {
			values[i] += rvec.values[i];
		}

		return *this;
	}

	Vector3 & Vector3::operator-=(Vector3 & rvec) {
		for (int i = 0; i < 3; ++i) {
			values[i] -= rvec.values[i];
		}

		return *this;
	}

}