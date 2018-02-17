#include <cmath>

#include "Math/Vector4.h"

namespace glwl {

	Vector4::Vector4(float f) {
		for (int i = 0; i < 4; ++i) {
			values[i] = f;
		}
	}

	Vector4::Vector4(float x, float y, float z, float w) {
		values[0] = x;
		values[1] = y;
		values[2] = z;
		values[3] = w;
	}

	void Vector4::setX(float x) {
		values[0] = x;
	}

	void Vector4::setY(float y) {
		values[1] = y;
	}

	void Vector4::setZ(float z) {
		values[2] = z;
	}

	void Vector4::setW(float w) {
		values[3] = w;
	}

	void Vector4::setVec(float x, float y, float z, float w) {
		*this = Vector4(x, y, z, w);
	}

	float Vector4::getX() {
		return values[0];
	}

	float Vector4::getY() {
		return values[1];
	}

	float Vector4::getZ() {
		return values[2];
	}

	float Vector4::getW() {
		return values[3];
	}

	float * Vector4::getData() {
		return values;
	}

	float Vector4::dot(Vector4 & lvec, Vector4 & rvec) {
		return lvec.values[0] * rvec.values[0] +
			lvec.values[1] * rvec.values[1] +
			lvec.values[2] * rvec.values[2] +
			lvec.values[3] * rvec.values[3];
	}

	Vector4 Vector4::operator+() {
		return *this;
	}

	Vector4 Vector4::operator-() {
		Vector4 result = *this;

		for (int i = 0; i < 4; ++i) {
			result.values[i] = -result.values[i];
		}

		return result;
	}

	Vector4 & Vector4::operator+=(Vector4 & rvec) {
		for (int i = 0; i < 4; ++i) {
			values[i] += rvec.values[i];
		}

		return *this;
	}

	Vector4 & Vector4::operator-=(Vector4 & rvec) {
		for (int i = 0; i < 4; ++i) {
			values[i] -= rvec.values[i];
		}

		return *this;
	}

	Vector4 Vector4::operator+(Vector4 & rvec) {
		Vector4 result = *this;

		return (result += rvec);
	}

	Vector4 Vector4::operator-(Vector4 & rvec) {
		Vector4 result = *this;

		return (result -= rvec);
	}

}
