#ifndef GLUT_TEXT_RENDERERS_H
#define GLUT_TEXT_RENDERERS_H

#include "TextRenderer_A.h"
#include "envFreeGlutTools.h"

#include <string>
using std::string;

class CBI_FREEGLUT_TOOLS GLUTTextRenderers: public TextRenderer_A
    {
    public:
	GLUTTextRenderers();
	virtual ~GLUTTextRenderers();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

	int charWidth(int character, const Font_A &font);
	int textWidth(const char* text, const Font_A &font);
	int textHeight(const char* text, const Font_A &font);

	/**
	 * If font is NULL use the default font!
	 */
	void renderText(float x, float y, const char* text, const Font_A &font);


	/**
	 * all value are relative to viewport, ie not in pixels !
	 */
	//static void renderBitmapStringCentered(float x, float y, int frameWidth, int frameHight, string title, const Fonts& font);
    };

#endif
