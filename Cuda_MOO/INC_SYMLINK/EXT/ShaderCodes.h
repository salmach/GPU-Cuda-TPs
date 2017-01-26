#ifndef SHADER_CODES_H
#define SHADER_CODES_H

#include "envBilatGL.h"
#include <GL/glew.h>

#include <vector>
#include <string>

using std::string;
using std::vector;

class CBI_GL ShaderCodes
    {
    public:

	ShaderCodes(vector<string> tabCodeSource);

	ShaderCodes(string* tabCodeSource,int count);

	virtual ~ShaderCodes();

	void afficherCode(const GLchar** code, unsigned int ligneCount); //Debug

	unsigned int getLigneCount() const;

	const GLchar** getSourceCode() const;

    private:
	unsigned int ligneCount;
	vector<string> tabCodeSource;
    };

#endif
