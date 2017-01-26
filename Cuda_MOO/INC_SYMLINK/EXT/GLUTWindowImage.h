#ifndef GLUT_WINDOW_IMAGE_H
#define GLUT_WINDOW_IMAGE_H

#include "envImage_FreeGlut.h"
#include "GLUTWindow.h"
#include "GLImageDisplayable.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_IMAGE_FREE_GLUT GLUTWindowImage: public GLUTWindow
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	GLUTWindowImage(GLImageDisplayable* ptrGLImageDisplayable, string title, int pxFrame = 0, int pyFrame = 0);

	virtual ~GLUTWindowImage();

	/*--------------------------------------*\
 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Fonction call a chaque fois que glut n'a rien a faire(idle) dans la mainLoop.
	 * CaD s'il n'y a pas d'evenents utilisateur (souris,clavier,joystick,repaint,etc...)
	 * La fonction animationStep de ImageMOO est called ici
	 */
	void idleFunc();

	/*--------------------------------------*\
 |*		Get			*|
	 \*-------------------------------------*/

    public:

	GLImageDisplayable* getPtrGLImage();

	/*--------------------------------------*\
	 |*		Attributs		*
	 \*-------------------------------------*/


    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
