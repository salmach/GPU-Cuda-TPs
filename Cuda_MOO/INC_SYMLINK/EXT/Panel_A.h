#ifndef PANEL_A_H
#define PANEL_A_H

#include "envBilatDisplayable.h"
#include "TextRenderer_A.h"
#include "FontLoader_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_DISPLAYABLE Panel_A
    {
    public:
	virtual ~Panel_A(){}

	virtual TextRenderer_A* getTextRenderer() =0;
	virtual FontLoader_A* getFontLoader() =0;

    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
