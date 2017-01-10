#ifndef _GOGLL_IMAGE_H_
#define _GOGLL_IMAGE_H_

#ifdef GOGLL_EXPORTS
#define DLLExports __declspec(dllexport)
#else
#define DLLExports __declspec(dllimport)
#endif

#include <vector>

namespace gogll {
	class Image {
	private:
		unsigned char id_length;

		char color_map_type;

		char image_type;

		short first_entry_index;
		short color_map_length;
		char color_map_entry_size;

		short x_origin;
		short y_origin;
		unsigned short image_width;
		unsigned short image_height;
		char pixel_depth;
		char image_descriptor;

		std::vector<char> image_id;

		std::vector<char> color_map_data;

		std::vector<float> image_data;

		char bytesPerPixel;
	public:
		DLLExports void loadTGA(const char * filePath);

		DLLExports float * getData();
	};
}

#endif
