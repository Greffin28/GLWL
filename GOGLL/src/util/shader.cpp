#include "util\shader.h"

namespace gogll {

	void Shader::loadvf(std::string vPath, std::string fPath) {
		std::ifstream in;
		std::string line;

		in.open(vPath);
		if (in.is_open()) {
			vSource = "";
			while (getline(in, line)) {
				vSource += line;
			}
			in.close();
		} else {
			std::cout << "Error on opening " << vPath << std::endl;
		}

		in.open(fPath);
		if (in.is_open()) {
			fSource = "";
			while (getline(in, line)) {
				fSource += line;
			}
			in.close();
		} else {
			std::cout << "Error on opening " << fPath << std::endl;
		}
	}

	void Shader::compilevf() {
		vShader = glCreateShader(GL_VERTEX_SHADER);
		fShader = glCreateShader(GL_FRAGMENT_SHADER);

		glvSource = vSource.c_str();
		glfSource = fSource.c_str();

		glShaderSource(vShader, 1, &glvSource, NULL);
		glShaderSource(fShader, 1, &glfSource, NULL);

		glCompileShader(vShader);
		glCompileShader(fShader);

		char logBuffer[512];
		int status;
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &status);
		if (!status) {
			glGetShaderInfoLog(vShader, 512, NULL, logBuffer);
			std::cout << "Vertex Shader Errors: " << std::endl << logBuffer << std::endl;
		}
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &status);
		if (!status) {
			glGetShaderInfoLog(fShader, 512, NULL, logBuffer);
			std::cout << "Fragment Shader Errors: " << std::endl << logBuffer << std::endl;
		}
	}

}