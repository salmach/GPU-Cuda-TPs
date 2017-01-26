#ifndef IMAGE_OPTION_H_
#define IMAGE_OPTION_H_

#include "envGLImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_GLIMAGE ImageOption
    {
    public:

	ImageOption(bool isSelectionEnable = true,bool isAnimationEnable = true, bool isOverlayDomaineEnable = false);


    public:

	// Inputs
	bool isAnimationEnable;
	bool isSelectionEnable;
	bool isOverlayDomaineEnable;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
