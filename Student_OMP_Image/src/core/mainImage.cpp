#include <iostream>

#include "RipplingProvider.h"
#include "Viewer_CPU.h"
#include "Settings_CPU.h"


#include "JuliaProvider.h"
#include "MandelbrotProvider.h"
using namespace cpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainImage(Settings& settings);

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
 |*		Private			*|
 \*-------------------------------------*/

int mainImage(Settings& settings)
    {
    cout << "\n[Image] mode" << endl;

    GLUTImageViewers::init(settings.getArgc(), settings.getArgv()); // only once

    // ImageOption : (boolean,boolean) : (isSelection,isAnimation)
    ImageOption zoomable(true);
    ImageOption nozoomable(false);

    //Viewer<RipplingProvider> rippling(nozoomable, 0, 0); //  imageOption px py
    Viewer<MandelbrotProvider> mandelbrot(zoomable, 25, 25); //  imageOption px py
    //Viewer<JuliaProvider> julia(zoomable, 25, 25); //  imageOption px py

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

