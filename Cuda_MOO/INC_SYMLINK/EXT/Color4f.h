#ifndef COLOR_4F_H
#define COLOR_4F_H
#include "envBilatGL.h"

class CBI_GL Color4f
    {

    public:

	Color4f(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);

    public:
	float r;
	float g;
	float b;
	float a;

	static Color4f RED;
	static Color4f BLUE;
	static Color4f GREEN;
	static Color4f YELLOW;
	static Color4f MANGANTA;
	static Color4f CYAN;
	static Color4f WHITE;
    };

#endif
