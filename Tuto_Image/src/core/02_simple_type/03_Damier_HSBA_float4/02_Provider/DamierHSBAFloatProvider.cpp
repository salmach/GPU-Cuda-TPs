#include "DamierHSBAFloatProvider.h"
#include "DamierHSBAFloat.h"

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
Animable_I<float4>* DamierHSBAFloatProvider::createAnimable(void)
    {
    DomaineMath domaineMath = DomaineMath(0, 0, 2 * PI, 2 * PI);

    // Animation;
    float dt = 2 * PI / 800;
    int n = 2;

    // Dimension
    int dw = 16 * 60 * 2;
    int dh = 16 * 60;

    return new DamierHSBAFloat(dw, dh, dt, n, domaineMath);
    }

/**
 * Override
 */
Image_I* DamierHSBAFloatProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_HSBA_float4(createAnimable(),colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
