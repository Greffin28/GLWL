#ifndef _GOGLL_MAT4_H_
#define _GOGLL_MAT4_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <cmath>

namespace gogll {
	class mat4 {
	private:
		float values[16] = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	public:
		DLLExports static mat4 identity();
		DLLExports static mat4 translate(float x, float y, float z);
		DLLExports static mat4 rotation(char axis, float angle);

		DLLExports void setValue(int i, float val);
		DLLExports float getValue(int i);
	};
}

#endif