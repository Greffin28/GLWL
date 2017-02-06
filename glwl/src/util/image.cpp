#include "util\image.h"

#include <iostream>
#include <fstream>

namespace gogll {

	void Image::loadTGA(const char * filePath) {
		std::ifstream is;
		is.open(filePath, std::ios::binary);
		if (is.is_open()) {
			is.read((char*) &id_length, sizeof(uint8_t));

			is.read((char*) &color_map_type, sizeof(uint8_t));

			is.read((char*) &image_type, sizeof(uint8_t));

			is.read((char*) &first_entry_index, sizeof(uint16_t));
			is.read((char*) &color_map_length, sizeof(uint16_t));
			is.read((char*) &color_map_entry_size, sizeof(uint8_t));

			is.read((char*) &x_origin, sizeof(uint16_t));
			is.read((char*) &y_origin, sizeof(uint16_t));
			is.read((char*) &image_width, sizeof(uint16_t));
			is.read((char*) &image_height, sizeof(uint16_t));
			is.read((char*) &pixel_depth, sizeof(uint8_t));
			is.read((char*) &image_descriptor, sizeof(uint8_t));

			bytesPerPixel = pixel_depth / 8;

			image_id.resize(id_length);
			is.read((char*) image_id.data(), id_length);
			color_map_data.resize(color_map_length);
			is.read((char*) color_map_data.data(), color_map_length);
			image_data.resize(image_width * image_height * bytesPerPixel);

			if (image_type == 2) {
				is.read((char*) image_data.data(), image_width * image_height * bytesPerPixel);
			} else if (image_type == 10) {
				uint8_t * ptr = image_data.data();
				unsigned int bytesDone = 0;

				while (bytesDone < image_data.size()) {
					uint8_t head;
					is.read((char*) &head, sizeof(uint8_t));
					if (head & 128) {
						head -= 127;

						std::vector<uint8_t> color;
						color.resize(bytesPerPixel);

						uint8_t * cptr = color.data();

						is.read((char*) cptr, bytesPerPixel);

						for (int i = 0; i < head; ++i) {
							std::memcpy(ptr + bytesDone, cptr, bytesPerPixel);
							bytesDone += bytesPerPixel;
						}
					} else {
						++head;
						is.read((char*) (ptr + bytesDone), bytesPerPixel * head * sizeof(uint8_t));
						bytesDone += bytesPerPixel * head;
					}
				}
			} else {
				std::cout << "TGA image type " << image_type << " is not supported" << std::endl;
			}

			uint8_t * ptr = image_data.data();
			std::vector<uint8_t> tmprow(bytesPerPixel * image_width);
			uint8_t * tmprowptr = tmprow.data();
			for (int y = 0; y < image_height / 2; ++y) {
				memcpy(tmprowptr, ptr + (y * image_width) * bytesPerPixel, bytesPerPixel * image_width);
				memcpy(ptr + (y * image_width) * bytesPerPixel, ptr + (image_height - 1 - y) * image_width * bytesPerPixel, bytesPerPixel * image_width);
				memcpy(ptr + (image_height - 1 - y) * image_width * bytesPerPixel, tmprowptr, bytesPerPixel * image_width);
			}
			for (int y = 0; y < image_height; ++y) {
				for (int x = 0; x < image_width; ++x) {
					uint8_t tmpb = *(ptr + (x + y * image_width) * bytesPerPixel);
					*(ptr + (x + y * image_width) * bytesPerPixel) = *(ptr + (x + y * image_width) * bytesPerPixel + 2);
					*(ptr + (x + y * image_width) * bytesPerPixel + 2) = tmpb;
				}
			}

			is.close();
		} else {
			std::cout << "Error on opening file" << std::endl;
		}
	}

	uint16_t Image::getWidth() {
		return image_width;
	}

	uint16_t Image::getHeight() {
		return image_height;
	}

	uint8_t Image::getDepth() {
		return pixel_depth;
	}

	uint8_t * Image::getData() {
		return image_data.data();
	}

}