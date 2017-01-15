#include "Mandelbrot.h"

#include "MathTools.h"

#include "ImageAnimable_CPU.h"
#include "DomaineMath_CPU.h"

#include "MandelbrotProvider.h"
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
Animable_I<uchar4>* MandelbrotProvider::createAnimable(void)
    {
    //DomaineMath a chercher des exemples de l enonce pdf
    DomaineMath domaineMath = DomaineMath(-2.1, -1.3, 0.8, 1.3);

    // Animation;
    int n = 2;

    // Dimension
    int dw = 16 * 60 * 2;
    int dh = 16 * 60;

    return new Mandelbrot(dw, dh, domaineMath);
    }

/**
 * Override
 */
Image_I* MandelbrotProvider::createImageGL(void)
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
