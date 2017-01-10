#include "util\image.h"

#include <iostream>
#include <fstream>

namespace gogll {

	void Image::loadTGA(const char * filePath) {
		std::ifstream is;
		is.open(filePath);
		if (is.is_open()) {
			std::vector<unsigned char> image_data_255;

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
			is.read(&image_descriptor, sizeof(char));

			bytesPerPixel = pixel_depth / 8;

			image_id.resize(id_length);
			color_map_data.resize(color_map_length);
			image_data_255.resize(image_width * image_height * bytesPerPixel);
			image_data.resize(image_width * image_height * bytesPerPixel);

			unsigned char * ptr255 = image_data_255.data();

			if (image_type == 2) {
				is.read((char*) ptr255, image_width * image_height * bytesPerPixel);
			} else if (image_type == 10) {
				unsigned int bytesDone = 0;

				while (bytesDone < image_data_255.size()) {
					unsigned char head;
					is.read((char*) &head, sizeof(char));
					if (head & 128) {
						head -= 127;

						std::vector<unsigned char> color;
						color.resize(bytesPerPixel);

						unsigned char * cptr = color.data();

						is.read((char*) cptr, bytesPerPixel);

						for (int i = 0; i < head; ++i) {
							std::memcpy(ptr255 + bytesDone, cptr, bytesPerPixel);
							bytesDone += bytesPerPixel;
						}
					} else {
						++head;
						is.read((char*) (ptr255 + bytesDone), bytesPerPixel * head * sizeof(char));
						bytesDone += bytesPerPixel * head;
					}
				}
			} else {
				std::cout << "TGA image type " << image_type << " is not supported" << std::endl;
			}

			float * ptr = image_data.data();
			for (unsigned int i = 0; i < image_data.size(); ++i) {
				*(ptr + i) = *(ptr255 + i) / 255.0f;
			}

			is.close();
		} else {
			std::cout << "Error on opening file" << std::endl;
		}
	}

	float * Image::getData() {
		return image_data.data();
	}

}