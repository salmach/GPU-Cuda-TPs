#ifndef TEXT_RENDERER_A_H
#define TEXT_RENDERER_A_H

#include "envBilatDisplayable.h"
#include "Font_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE TextRenderer_A
    {
//	enum VertialAlignement {TOP,CENTER,BOTTOM};
//	enum HorizontalAlignement {LEFT,CENTER,RIGHT};
    public:
	virtual ~TextRenderer_A()
	    {
	    }

	virtual int charWidth(int character,const Font_A &font)=0;
	virtual int textWidth(const char* text,const Font_A &font) =0;
	virtual int textHeight(const char* text,const Font_A &font) =0;

	/**
	 * If font is NULL use the default font!
	 */
	virtual void renderText(float x, float y, const char* text, const Font_A &font)=0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
