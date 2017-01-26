#ifndef GLUT_FONT_H
#define GLUT_FONT_H
#include "Font_A.h"
#include "envFreeGlutTools.h"
#include "GLConfig.h"


#include <string>

using std::string;

class CBI_FREEGLUT_TOOLS GLUTFont: public Font_A
    {
    public:
	/**
	 * fontWidth and fontHeight in pixels
	 *
	 * glutFont :
	 *
	 * 	GLUT_BITMAP_8_BY_13, 8x13 pixels
	 * 	GLUT_BITMAP_9_BY_15, 9x15 pixels
	 * 	GLUT_BITMAP_TIMES_ROMAN_10
	 * 	GLUT_BITMAP_TIMES_ROMAN_24
	 * 	GLUT_BITMAP_HELVETICA_10
	 * 	GLUT_BITMAP_HELVETICA_12
	 * 	GLUT_BITMAP_HELVETICA_18
	 */
	GLUTFont(int fontHeight,void* glutFont);
	GLUTFont(const GLUTFont& source);
	virtual ~GLUTFont();


    public:
	void* glutFont;

    };

#endif
