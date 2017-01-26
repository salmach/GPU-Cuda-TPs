#ifndef COLORCHAR_H
#define COLORCHAR_H

#include "envBilatGL.h"

class CBI_GL ColorChar
    {
    public:

	ColorChar(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0);

	virtual ~ColorChar();
    public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	static ColorChar RED;
	static ColorChar BLUE;
	static ColorChar GREEN;
	static ColorChar YELLOW;
	static ColorChar MANGANTA;
	static ColorChar CYAN;
	static ColorChar WHITE;
    };

#endif
