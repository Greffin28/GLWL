#include "util\image.h"

#include <iostream>
#include <fstream>

namespace gogll {

	void Image::loadTGA(const char * filePath) {
		std::ifstream is;
		is.open(filePath);
		if (is.is_open()) {
			is.read((char*) &id_length, sizeof(char));

			is.read(&color_map_type, sizeof(char));

			is.read(&image_type, sizeof(char));

			is.read((char*) &first_entry_index, sizeof(short));
			is.read((char*) &color_map_length, sizeof(short));
			is.read(&color_map_entry_size, sizeof(char));

			is.read((char*) &x_origin, sizeof(short));
			is.read((char*) &y_origin, sizeof(short));
			is.read((char*) &image_width, sizeof(short));
			is.read((char*) &image_height, sizeof(short));
			is.read(&pixel_depth, sizeof(char));

			bytesPerPixel = pixel_depth / 8;

			image_id.resize(id_length);
			color_map_data.resize(color_map_length);
			image_data.resize(image_width * image_height * bytesPerPixel);

			if (image_type == 2) {
				is.read((char*) image_data.data(), image_width * image_height * bytesPerPixel);
			} else if (image_type == 10) {
				unsigned char * ptr = image_data.data();
				int bytesDone = 0;

				while (bytesDone < image_data.size()) {
					unsigned char head;
					is.read((char*) &head, sizeof(char));
					if (head & 128) {
						head -= 127;

						std::vector<unsigned char> color;
						color.resize(bytesPerPixel);

						unsigned char * cptr = color.data();

						is.read((char*) cptr, bytesPerPixel);

						for (int i = 0; i < head; ++i) {
							std::memcpy(ptr + bytesDone, cptr, bytesPerPixel);
							bytesDone += bytesPerPixel;
						}
					} else {
						++head;
						is.read((char*) (ptr + bytesDone), bytesPerPixel * head * sizeof(char));
						bytesDone += bytesPerPixel * head;
					}
				}
			} else {
				std::cout << "TGA image type " << image_type << " is not supported" << std::endl;
			}

			is.close();
		} else {
			std::cout << "Error on opening file" << std::endl;
		}
	}

}