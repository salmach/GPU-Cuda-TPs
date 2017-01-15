#include "JuliaProvider.h"

#include "Julia.h"

#include "MathTools.h"

#include "ImageAnimable_CPU.h"
#include "DomaineMath_CPU.h"
using namespace cpu;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Surcharge		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* JuliaProvider::createAnimable(void)
    {
    //DomaineMath a chercher des exemples de l enonce pdf
    DomaineMath domaineMath = DomaineMath(-1.7, -1, 1.7, 1);

    // Animation;
    int n = 2;

    // Dimension
    int dw = 16 * 60 * 2;
    int dh = 16 * 60;

    return new Julia(dw, dh, domaineMath);
    }

/**
 * Override
 */
Image_I* JuliaProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_RGBA_uchar4(createAnimable(),colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
