#include "util\texture.h"

namespace gogll {

	Texture::Texture() {
		glGenTextures(1, &tex);
	}

	void Texture::bind() {
		glBindTexture(GL_TEXTURE_2D, tex);
	}

	void Texture::unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &tex);
	}

}