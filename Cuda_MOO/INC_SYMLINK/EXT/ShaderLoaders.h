#ifndef SHADER_LOADERS_H
#define SHADER_LOADERS_H

#include "envBilatGL.h"
#include "ShaderPrograms.h"


class CBI_GL ShaderLoaders
    {
    public:

	ShaderLoaders();
	virtual ~ShaderLoaders();

	static Shaders* loadVertexShader(string fileName);

	static Shaders* loadFragmentShader(string fileName);

	static ShaderCodes* loadShaderSourceCode(string fileName);

	static ShaderPrograms* loadShaderProgram(string fileNameVertexShader, string fileNameFragmentShader);

    private:
	static Shaders* loadShader(GLenum type, string fileName);
    };

#endif
