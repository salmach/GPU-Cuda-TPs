#include "RipplingProvider.h"
#include "Rippling.h"

#include "MathTools.h"
#include "Grid.h"



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

/**
 * Override
 */
Animable_I<uchar4>* RipplingProvider::createAnimable()
    {
    // Animation;
    float dt = 2 * PI / 10;

    // Dimension
    int dw = 16 * 60;
    int dh = 16 * 60;

    // Grid Cuda
    Grid grid(32,32);  // definissez une grille cuda (dg, db)
    //NOT sure of syntax !!
    //Grid(const dim3& dg = dim3(1, 1, 1), const dim3& db = dim3(1, 1, 1));
    //int grid::dg = 32 ;
    //int grid::db = 32 ;
    return new Rippling(grid,dw, dh, dt);
    }

/**
 * Override
 */
Image_I* RipplingProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }



/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
