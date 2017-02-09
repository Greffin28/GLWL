#include "util\frame_buffer.h"

namespace glwl {

	FrameBuffer::FrameBuffer() {
		glGenFramebuffers(1, &fbo);
	}

	void FrameBuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	}

	void FrameBuffer::unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	FrameBuffer::~FrameBuffer() {
		glDeleteFramebuffers(1, &fbo);
	}

}