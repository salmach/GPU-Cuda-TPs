#ifndef GLUT_FONT_LOADER_H
#define GLUT_FONT_LOADER_H

#include "FontLoader_A.h"
#include "envFreeGlutTools.h"

#include <map>
using std::map;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_FREEGLUT_TOOLS GLUTFontLoader: public FontLoader_A
    {
    public:
	GLUTFontLoader();
	virtual ~GLUTFontLoader();

	virtual const Font_A* loadFont(string fontName);
	virtual const Font_A* loadFont(FontType type=HELVETICA_12);
    private :
	map<FontType, const Font_A*> mapGlutFont;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
