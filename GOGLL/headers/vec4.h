#ifndef _GOGLL_VEC4_H_
#define _GOGLL_VEC4_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport);
#else
#define DLLExports __declspec(dllimport);
#endif

namespace gogll {
	class vec4 {
	private:
		float values[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	public:

	};
}

#endif