#ifndef FONT_LOADER_A_H
#define FONT_LOADER_A_H

#include "envBilatDisplayable.h"
#include "Font_A.h"

#include <string>
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum FontType
    {
    BITMAP_13,
    BITMAP_15,
    TIMES_ROMAN_10,
    TIMES_ROMAN_24,
    HELVETICA_10,
    HELVETICA_12,
    HELVETICA_18
    };

class CBI_DISPLAYABLE FontLoader_A
    {
    public:
	virtual ~FontLoader_A()
	    {
	    }

	virtual const Font_A* loadFont(string fontName) =0;

	virtual const Font_A* loadFont(FontType type = HELVETICA_12) =0;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
