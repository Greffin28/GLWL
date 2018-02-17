#include "Math/Vector3.h"

#include <cmath>

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

	float Vector3::dot(const Vector3 & lvec, const Vector3 & rvec) {
		return lvec.values[0] * rvec.values[0] +
			lvec.values[1] * rvec.values[1] +
			lvec.values[2] * rvec.values[2];
	}

	Vector3 Vector3::cross(const Vector3 & lvec, const Vector3 & rvec) {
		return Vector3(
			lvec.values[1] * rvec.values[2] - rvec.values[1] * lvec.values[2],
			lvec.values[2] * rvec.values[0] - rvec.values[2] * lvec.values[0],
			lvec.values[0] * rvec.values[1] - rvec.values[0] * lvec.values[1]
		);
	}

	Vector3 & Vector3::normalize() {
		float length = getLength();

		for (int i = 0; i < 3; ++i) {
			values[i] /= length;
		}

		return *this;
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

	float Vector3::getX() const {
		return values[0];
	}

	float Vector3::getY() const {
		return values[1];
	}

	float Vector3::getZ() const {
		return values[2];
	}

	const float * Vector3::getData() const {
		return values;
	}

	float Vector3::getLength() const {
		float toSqrt = 0;
		for (int i = 0; i < 3; ++i) {
			toSqrt += values[i] * values[i];
		}

		return std::sqrtf(toSqrt);
	}

	Vector3 Vector3::getNormalize() const {
		Vector3 result = *this;

		return result.normalize();
	}

	Vector3 Vector3::operator+() const {
		return *this;
	}

	Vector3 Vector3::operator-() const {
		Vector3 result = *this;

		for (int i = 0; i < 3; ++i) {
			result.values[i] = -result.values[i];
		}

		return result;
	}

	Vector3 & Vector3::operator+=(const Vector3 & rvec) {
		for (int i = 0; i < 3; ++i) {
			values[i] += rvec.values[i];
		}

		return *this;
	}

	Vector3 & Vector3::operator-=(const Vector3 & rvec) {
		for (int i = 0; i < 3; ++i) {
			values[i] -= rvec.values[i];
		}

		return *this;
	}

	Vector3 & Vector3::operator*=(float f) {
		for (int i = 0; i < 3; ++i) {
			values[i] *= f;
		}

		return *this;
	}

	Vector3 Vector3::operator+(const Vector3 & rvec) const {
		Vector3 result = *this;

		return (result += rvec);
	}

	Vector3 Vector3::operator-(const Vector3 & rvec) const {
		Vector3 result = *this;

		return (result -= rvec);
	}

	Vector3 Vector3::operator*(float f) const {
		Vector3 result = *this;

		return (result *= f);
	}

	Vector3 operator*(float f, const Vector3 & rvec) {
		return rvec * f;
	}

}