#include <cmath>

#include "Math/Vector4.h"

namespace glwl {

	Vector4::Vector4(float f) {
		values[0] = values[1] = values[2] = values[3] = f;
	}

	Vector4::Vector4(float x, float y, float z, float w) {
		values[0] = x;
		values[1] = y;
		values[2] = z;
		values[3] = w;
	}

	void Vector4::setValue(int i, float val) {
		if (i < 0 || i >= 4) return;
		values[i] = val;
	}

	float Vector4::getValue(int i) {
		if (i < 0 || i >= 4) return 0;
		return values[i];
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

	Vector4 Vector4::operator+(Vector4 & rvec) {
		Vector4 result = *this;

		return (result += rvec);
	}

	Vector4 Vector4::operator-(Vector4 & rvec) {
		Vector4 result = *this;

		return (result -= rvec);
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

}
