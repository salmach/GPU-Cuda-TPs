#ifndef SHADERS_H
#define SHADERS_H

#include "ShaderCodes.h"
#include <GL/glew.h>


/**
 * Use ShaderLoader to crate a Shader
 * But shaderType is GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
 */
class CBI_GL Shaders
    {
    public:

	Shaders(GLenum shaderType,ShaderCodes* ptrShaderCode);

	virtual ~Shaders();

	void init();
	void release();
	GLuint getShaderID() const;

    private :
	GLenum shaderType;
	ShaderCodes* ptrShaderCode;
	GLuint shaderID;
    };

#endif
