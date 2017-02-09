#ifndef _GOGLL_VEC4_H_
#define _GOGLL_VEC4_H_

#ifdef GLWL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

namespace glwl {
	class vec4 {
	private:
		float values[4];
	public:
		DLLExports vec4() {};
		DLLExports vec4(float f);
		DLLExports vec4(float x, float y, float z, float w = 1.0f);

		DLLExports void setValue(int i, float val);
		DLLExports float getValue(int i) const;
		DLLExports float * getData();
	};
}

#endif