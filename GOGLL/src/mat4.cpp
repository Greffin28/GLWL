#include "mat4.h"

namespace gogll {

	mat4 mat4::identity() {
		mat4 identity;
		return identity;
	}

	mat4 mat4::translate(float x, float y, float z) {
		mat4 mat;
		
		mat.setValue(0 + 3 * 4, x);
		mat.setValue(1 + 3 * 4, y);
		mat.setValue(2 + 3 * 4, z);

		return mat;
	}

	mat4 mat4::rotation(char axis, float angle) {
		mat4 mat;

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
			mat.setValue(1 + 2 * 4, -sin(angle));
			mat.setValue(2 + 1 * 4, sin(angle));
			mat.setValue(2 + 2 * 4, cos(angle));
		}

		return mat;
	}

	mat4 mat4::ortho(float l, float t, float r, float b, float n, float f) {
		mat4 mat;

		mat.setValue(0 + 0 * 4, 2.0f / (r - l));
		mat.setValue(0 + 3 * 4, -(r + l) / (r - l));
		mat.setValue(1 + 0 * 4, -2.0f / (b - t));
		mat.setValue(1 + 3 * 4, (b + t) / (b - t));
		mat.setValue(2 + 0 * 4, 2.0f / (f - n));
		mat.setValue(2 + 3 * 4, -(f + n) / (f - b));

		return mat;
	}

	mat4 mat4::perspective(int width, int height, float fov, float n, float f) {
		mat4 mat;

		fov = fov * PI / 180.0f;
		float ratio = 1.0f * width / height;



		return mat;
	}

	void mat4::setValue(int i, float val) {
		if (i < 0 || i >= 16) return;
		values[i] = val;
	}

	float mat4::getValue(int i) {
		if (i < 0 || i >= 16) return 0.0f;
		return values[i];
	}
}
