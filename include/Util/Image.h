#pragma once

#ifdef _WIN32
	#ifdef GLWL_EXPORTS
	#define DLLExports __declspec(dllexport)
	#else
	#define DLLExports __declspec(dllimport)
	#endif
#else
#define DLLExports
#endif

#include <vector>
#include <cstdint>

namespace glwl {
	class DLLExports Image {
	private:
		uint8_t id_length;

		uint8_t color_map_type;

		uint8_t image_type;

		uint16_t first_entry_index;
		uint16_t color_map_length;
		uint8_t color_map_entry_size;

		uint16_t x_origin;
		uint16_t y_origin;
		uint16_t image_width;
		uint16_t image_height;
		uint8_t pixel_depth;
		uint8_t image_descriptor;

		std::vector<uint8_t> image_id;

		std::vector<uint8_t> color_map_data;

		std::vector<uint8_t> image_data;

		uint8_t bytesPerPixel;
	public:
		void loadTGA(const char * filePath);

		uint16_t getWidth();
		uint16_t getHeight();
		uint8_t getDepth();
		uint8_t * getData();
	};
}