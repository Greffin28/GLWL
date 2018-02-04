#include "Util/FrameBuffer.h"

#include <iostream>

#include <GL/glew.h>

namespace glwl {

	FrameBuffer::FrameBuffer() {
		
	}

	void FrameBuffer::init() {
		glGenFramebuffers(1, &fbo);
	}

	void FrameBuffer::setUp(int width, int height, bool depth) {
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

	unsigned int FrameBuffer::getFBO() {
		return fbo;
	}

	FrameBuffer::~FrameBuffer() {
		glDeleteRenderbuffers(1, &rbo);
		glDeleteFramebuffers(1, &fbo);
	}

}
