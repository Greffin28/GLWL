#include "Util/FrameBuffer.h"

#include <iostream>

namespace glwl {

	FrameBuffer::FrameBuffer() {
		glGenFramebuffers(1, &fbo);
	}

	FrameBuffer::FrameBuffer(int width, int height, bool depth) {
		glGenFramebuffers(1, &fbo);
		tex.blankTexture(width, height);
		bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex.getID(), 0);
		if (depth) {
			glGenRenderbuffers(1, &rbo);
			glBindRenderbuffer(GL_RENDERBUFFER, rbo);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
		unbind();
	}

	void FrameBuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	}

	void FrameBuffer::unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	GLuint FrameBuffer::getFBO() {
		return fbo;
	}

	FrameBuffer::~FrameBuffer() {
		glDeleteRenderbuffers(1, &rbo);
		glDeleteFramebuffers(1, &fbo);
	}

}
