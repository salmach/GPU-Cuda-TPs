#include <iostream>

#include "DamierProvider.h"
#include "VagueProvider.h"
#include "VagueGrayProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"

#include "EventProvider.h"
#include "OverlayProvider.h"
#include "DomaineProvider.h"

#include "MyGLUTWindow.h"
#include "MyDisplayableProvider.h"

#include "Viewer_CPU.h"
#include "Settings_CPU.h"
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

    // ImageOption : (boolean,boolean) : (isSelection,isAnimation=true)
    ImageOption zoomable(true);
    ImageOption nozoomable(false);

    Viewer<VagueProvider> vague(nozoomable, 0, 0); 				//  imageOption px py
    /*Viewer<DamierProvider> damier(zoomable, 25, 25);				//  imageOption px py
    Viewer<VagueGrayProvider> vagueGrayUchar(nozoomable, 50, 50); 		//  imageOption px py
    Viewer<DamierRGBAFloatProvider> damierRGBAfloat4(zoomable, 75, 75); 	//  imageOption px py
    Viewer<DamierHSBAFloatProvider> damierHSBAfloat4(zoomable, 100, 100);	//  imageOption px py
    Viewer<DamierHueFloatProvider> damierHuefloat(zoomable, 125, 125);		//  imageOption px py
    Viewer<EventProvider> eventProvider(zoomable, 150, 150);			//  imageOption px py
    Viewer<OverlayProvider> overlayProvider(zoomable, 175, 175);		//  imageOption px py
    Viewer<DomaineProvider> domaineProvider(zoomable, 200, 200);		//  imageOption px py
    // setSize of frame, size of image  don't change, a texture work for you to adapt the image to the size of the frame
    overlayProvider.setSize(400,400);
*/

    // Custom : Advanced
     Displayable_A* ptrMyDisplayable = MyDisplayableProvider::createGL();
     MyGLUTWindow myGlutWindow(ptrMyDisplayable, "Triangle OpenGL Custom Displayable", 600, 600, 250, 250); // scene OpenGL // (w,h,px,py)

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    delete ptrMyDisplayable;

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

