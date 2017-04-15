#include "Math/Matrix4.h"
#include "Math/Vector4.h"

namespace glwl {

	Matrix4::Matrix4() {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				values[x + y * 4] = (x == y) ? 1 : 0;
			}
		}
	}

	Matrix4 Matrix4::identity() {
		return mat4();
	}

	Matrix4 Matrix4::translate(float x, float y, float z) {
		Matrix4 mat;
		
		mat.setValue(0 + 3 * 4, x);
		mat.setValue(1 + 3 * 4, y);
		mat.setValue(2 + 3 * 4, z);

		return mat;
	}
	Matrix4 Matrix4::scale(float x, float y, float z) {
		Matrix4 mat;

		mat.setValue(0 + 0 * 4, x);
		mat.setValue(1 + 1 * 4, y);
		mat.setValue(2 + 2 * 4, z);

		return mat;
	}

	Matrix4 Matrix4::rotation(char axis, float angle) {
		Matrix4 mat;

		angle = angle * PI / 180.0f;

		if (axis == 'Z' || axis == 'z') {
			mat.setValue(0 + 0 * 4, cos(angle));
			mat.setValue(0 + 1 * 4, -sin(angle));
			mat.setValue(1 + 0 * 4, sin(angle));
			mat.setValue(1 + 1 * 4, cos(angle));
		} else if (axis == 'Y' || axis == 'y') {
			mat.setValue(0 + 0 * 4, cos(angle));
			mat.setValue(0 + 2 * 4, -sin(angle));
			mat.setValue(2 + 0 * 4, sin(angle));
			mat.setValue(2 + 2 * 4, cos(angle));
		} else if (axis == 'X' || axis == 'x') {
			mat.setValue(1 + 1 * 4, cos(angle));
			mat.setValue(1 + 2 * 4, sin(angle));
			mat.setValue(2 + 1 * 4, -sin(angle));
			mat.setValue(2 + 2 * 4, cos(angle));
		}

		return mat;
	}

	Matrix4 Matrix4::ortho(float l, float t, float r, float b, float n, float f) {
		Matrix4 mat;

		mat.setValue(0 + 0 * 4, 2.0f / (r - l));
		mat.setValue(0 + 3 * 4, -(r + l) / (r - l));
		mat.setValue(1 + 1 * 4, -2.0f / (b - t));
		mat.setValue(1 + 3 * 4, (b + t) / (b - t));
		mat.setValue(2 + 2 * 4, 2.0f / (f - n));
		mat.setValue(2 + 3 * 4, -(f + n) / (f - n));

		return mat;
	}

	Matrix4 Matrix4::perspective(int width, int height, float fov, float n, float f) {
		Matrix4 mat;

		fov = 0.5f * fov * PI / 180.0f;
		float ratio = 1.0f * width / height;
		
		float halfScreenNear = n * tan(fov);
		float r = halfScreenNear;
		float l = -r;
		float t = halfScreenNear / ratio;
		float b = -t;

		mat.setValue(0 + 0 * 4, 2.0f * n / (r - l));
		mat.setValue(0 + 2 * 4, -(r + l) / (r - l));
		mat.setValue(1 + 1 * 4, -2.0f * n / (b - t));
		mat.setValue(1 + 2 * 4, (b + t) / (b - t));
		mat.setValue(2 + 2 * 4, (f + n) / (f - n));
		mat.setValue(2 + 3 * 4, -2.0f * n * f / (f - n));
		mat.setValue(3 + 2 * 4, 1.0f);
		mat.setValue(3 + 3 * 4, 0.0f);

		return mat;
	}

	void Matrix4::setValue(int i, float val) {
		if (i < 0 || i >= 16) return;
		values[i] = val;
	}

	float Matrix4::getValue(int i) {
		if (i < 0 || i >= 16) return 0.0f;
		return values[i];
	}

	float * Matrix4::getData() {
		return values;
	}

	Matrix4 Matrix4::operator*(Matrix4 &rmat) {
		Matrix4 result = *this;

		return (result *= rmat);
	}

	Matrix4 Matrix4::operator*=(Matrix4 &rmat) {
		Matrix4 temp = *this;

		float * dp1 = temp.getData();
		float * dp2 = rmat.getData();
		float * pv = values - 1;

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float val = 0;
				float *p1 = dp1 + x;
				float *p2 = dp2 + y * 4 - 1;
				for (int i = 0; i < 4; i++) {
					val += *(p1) * *(++p2);
					p1 += 4;
				}
				*(++pv) = val;
			}
		}

		return *this;
	}

	Vector4 Matrix4::operator*(Vector4 &rvec) {
		Vector4 result;
		for (int x = 0; x < 4; x++) {
			float val = 0;
			float *p1, *p2;
			p1 = &getData()[x];
			p2 = rvec.getData() - 1;
			for (int i = 0; i < 4; i++) {
				val += *(p1) * *(++p2);
				p1 += 4;
			}
			result.setValue(x, val);
		}
		return result;
	}
}
