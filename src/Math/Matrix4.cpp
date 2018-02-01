#include <cmath>

#include "Math/Matrix4.h"
#include "Math/Vector4.h"

namespace glwl {

	Matrix4::Matrix4() {
		float values[] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		setValues(values);
	}

	Matrix4::Matrix4(float * values) {
		setValues(values);
	}

	Matrix4 Matrix4::identity() {
		return Matrix4();
	}

	Matrix4 Matrix4::translate(float x, float y, float z) {
		float values[] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			x, y, z, 1
		};

		return Matrix4(values);
	}
	Matrix4 Matrix4::scale(float x, float y, float z) {
		float values[] = {
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1
		};

		return Matrix4(values);
	}

	Matrix4 Matrix4::rotation(char axis, float angle) {
		angle *= PI / 180.0f;

		float cos = std::cos(angle);
		float sin = std::sin(angle);

		if (axis == 'Z' || axis == 'z') {
			float values[] = {
				cos	, sin	, 0, 0,
				-sin, cos	, 0, 0,
				0	, 0		, 1, 0,
				0	, 0		, 0, 1
			};

			return Matrix4(values);
		} else if (axis == 'Y' || axis == 'y') {
			float values[] = {
				cos	, 0, sin, 0,
				0	, 1, 0	, 0,
				-sin, 0, cos, 0,
				0	, 0, 0	, 1
			};

			return Matrix4(values);
		} else if (axis == 'X' || axis == 'x') {
			float values[] = {
				1, 0	, 0		, 0,
				0, cos	, -sin	, 0,
				0, sin	, cos	, 0,
				0, 0	, 0		, 1
			};

			return Matrix4(values);
		}

		return Matrix4();
	}

	Matrix4 Matrix4::ortho(float l, float t, float r, float b, float n, float f) {
		float values[] = {
			2.0f / (r - l)		, 0					, 0					, 0,
			0					, -2.0f / (b - t)	, 0					, 0,
			0					, 0					, 2.0f / (f - n)	, 0,
			-(r + l) / (r - l)	, (b + t) / (b - t)	, -(f + n) / (f - n), 1
		};

		return Matrix4(values);
	}

	Matrix4 Matrix4::perspective(int width, int height, float fov, float n, float f) {
		Matrix4 mat;

		fov *= 0.5f * PI / 180.0f;
		float ratio = 1.0f * width / height;
		
		float halfScreenNear = n * tan(fov);
		float r = halfScreenNear;
		float l = -r;
		float t = halfScreenNear / ratio;
		float b = -t;

		float values[] = {
			2.0f * n / (r - l)	, 0						, 0							, 0,
			0					, -2.0f * n / (b - t)	, 0							, 0,
			-(r + l) / (r - l)	, (b + t) / (b - t)		, (f + n) / (f - n)			, 1,
			0					, 0						, -2.0f * n * f / (f - n)	, 0
		};

		return Matrix4(values);
	}

	Matrix4 & Matrix4::transpose() {
		Matrix4 temp = *this;

		setValue(1, 0, temp.getValue(0, 1));
		setValue(2, 0, temp.getValue(0, 2));
		setValue(3, 0, temp.getValue(0, 3));
		setValue(2, 1, temp.getValue(1, 2));
		setValue(3, 1, temp.getValue(1, 3));
		setValue(3, 2, temp.getValue(2, 3));

		setValue(0, 1, temp.getValue(1, 0));
		setValue(0, 2, temp.getValue(2, 0));
		setValue(0, 3, temp.getValue(3, 0));
		setValue(1, 2, temp.getValue(2, 1));
		setValue(1, 3, temp.getValue(3, 1));
		setValue(2, 3, temp.getValue(3, 2));

		return *this;
	}

	void Matrix4::setValue(int i, float val) {
		if (i < 0 || i >= 16) return;
		values[i] = val;
	}

	void Matrix4::setValue(int x, int y, float val) {
		if (x < 0 || x >= 4 || y < 0 || y >= 4) return;
		values[x + y * 4] = val;
	}

	void Matrix4::setValues(float * values) {
		for (int i = 0; i < 16; ++i) {
			this->values[i] = values[i];
		}
	}

	float Matrix4::getValue(int i) {
		if (i < 0 || i >= 16) return 0;
		return values[i];
	}

	float Matrix4::getValue(int x, int y) {
		if (x < 0 || x >= 4 || y < 0 || y >= 4) return 0;
		return values[x + y * 4];
	}

	float * Matrix4::getData() {
		return values;
	}

	Matrix4 Matrix4::getTranspose() {
		Matrix4 mat = *this;

		return mat.transpose();
	}

	Matrix4 Matrix4::operator+() {
		return *this;
	}

	Matrix4 Matrix4::operator-() {
		Matrix4 result = *this;
		for (int i = 0; i < 16; ++i) {
			result.values[i] = -result.values[i];
		}
		return result;
	}

	Matrix4 Matrix4::operator+(Matrix4 & rmat) {
		Matrix4 result = *this;

		return (result += rmat);
	}

	Matrix4 Matrix4::operator-(Matrix4 & rmat) {
		Matrix4 result = *this;

		return (result -= rmat);
	}

	Matrix4 Matrix4::operator*(Matrix4 & rmat) {
		Matrix4 result = *this;

		return (result *= rmat);
	}

	Matrix4 Matrix4::operator*(float value) {
		Matrix4 result = *this;

		return (result *= value);
	}

	Matrix4 & Matrix4::operator+=(Matrix4 & rmat) {
		for (int i = 0; i < 16; ++i) {
			values[i] += rmat.values[i];
		}

		return *this;
	}

	Matrix4 & Matrix4::operator-=(Matrix4 & rmat) {
		for (int i = 0; i < 16; ++i) {
			values[i] -= rmat.values[i];
		}

		return *this;
	}

	Matrix4 & Matrix4::operator*=(Matrix4 & rmat) {
		Matrix4 temp = *this;
		/*for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				values[x + y * 4] = temp.values[x + 0 * 4] * rmat.values[0 + y * 4] +
					temp.values[x + 1 * 4] * rmat.values[1 + y * 4] +
					temp.values[x + 2 * 4] * rmat.values[2 + y * 4] +
					temp.values[x + 3 * 4] * rmat.values[3 + y * 4];
			}
		}*/
		
		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				float val = 0;
				for (int i = 0; i < 4; ++i) {
					val += temp.values[x + i * 4] * rmat.values[i + y * 4];
				}
				values[x + y * 4] = val;
			}
		}

		return *this;
	}

	Matrix4 & Matrix4::operator*=(float value) {
		for (int i = 0; i < 16; ++i) {
			values[i] *= value;
		}

		return *this;
	}

	Vector4 Matrix4::operator*(Vector4 & rvec) {
		Vector4 result;

		float * rptr = result.getData();
		float * vptr = rvec.getData();

		for (int i = 0; i < 4; ++i) {
			float val = 0;
			for (int j = 0; j < 4; ++j) {
				val += values[i + j * 4] * *(vptr + j);
			}
			*(rptr + i) = val;
		}

		return result;
	}

	Matrix4 operator*(float value, Matrix4 & rmat) {
		Matrix4 result = rmat;

		return (result *= value);
	}

}
