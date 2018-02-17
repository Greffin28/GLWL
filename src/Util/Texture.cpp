#include "Util/Texture.h"
#include "Util/Image.h"

#include <GL/glew.h>

namespace glwl {

	Texture::Texture() {
		
	}

	Texture::~Texture() {
		glDeleteTextures(1, &tex);
	}

	void Texture::init() {
		glGenTextures(1, &tex);

		minFilter = GL_LINEAR_MIPMAP_NEAREST;
		magFilter = GL_NEAREST;
		warpS = GL_REPEAT;
		warpT = GL_REPEAT;
	}

	void Texture::blankTexture(int width, int height) {
		bind();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, warpS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, warpT);

		unbind();
	}

	void Texture::setImage2D(const Image & image) {
		bind();

		GLenum internalFormat = GL_RGB;
		GLenum imageFormat = GL_RGB;

		if (image.getDepth() == 32) {
			internalFormat = GL_RGBA;
			imageFormat = GL_RGBA;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, image.getWidth(), image.getHeight(), 0, imageFormat, GL_UNSIGNED_BYTE, image.getData());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, warpS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, warpT);

		glGenerateMipmap(GL_TEXTURE_2D);

		unbind();
	}

	void Texture::bind() {
		glBindTexture(GL_TEXTURE_2D, tex);
	}

	void Texture::unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::setMinFilter(unsigned int mode) {
		minFilter = mode;
	}

	void Texture::setMagFilter(unsigned int mode) {
		magFilter = mode;
	}

	void Texture::setWarpS(unsigned int mode) {
		warpS = mode;
	}

	void Texture::setWarpT(unsigned int mode) {
		warpT = mode;
	}

	unsigned int Texture::getID() const {
		return tex;
	}

}
