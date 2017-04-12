#include "math/vec4.h"

namespace glwl {

	vec4::vec4(float f) {
		values[0] = values[1] = values[2] = values[3] = f;
	}

	vec4::vec4(float x, float y, float z, float w) {
		values[0] = x;
		values[1] = y;
		values[2] = z;
		values[3] = w;
	}

	void vec4::setValue(int i, float val) {
		if (i < 0 || i >= 4) return;
		values[i] = val;
	}

	float vec4::getValue(int i) const {
		if (i < 0 || i >= 4) return 0;
		return values[i];
	}

	float * vec4::getData() {
		return values;
	}

}
