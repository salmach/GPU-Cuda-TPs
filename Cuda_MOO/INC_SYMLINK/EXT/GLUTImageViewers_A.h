#ifndef GLUT_IMAGE_VIEWERS_A_H_
#define GLUT_IMAGE_VIEWERS_A_H_

#include "envImage_FreeGlut.h"
#include "GLUTWindowImage.h"
#include "GLUTWindowManagers.h"
#include "GLImageFactory_I.h"
#include "Image_I.h"
#include "ImageOption.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class CBI_IMAGE_FREE_GLUT GLUTImageViewers_A
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	GLUTImageViewers_A(Image_I* ptrImage,GLImageFactory_I* ptrImageFactory,ImageOption imageOption=ImageOption(), int pxFrame = 0, int pyFrame = 0);


    public:

	virtual ~GLUTImageViewers_A();

	/*--------------------------------------*\
 	|*		Methodes		*|
	 \*-------------------------------------*/

	static void init(int argc, char** argv);

	/**
	 * Attention appel bloquant !
	 */
	static void runALL();

	/*--------------------------------------*\
	 |*		Get			*|
	 \*-------------------------------------*/

	/**
	 * Cast to Images
	 *
	 * Sample :
	 *
	 *  Images_I* ptrImageMOO_A=this->getImageMOO();
	 *
	 *  MyImages ptrImageMOO=dynamic_cast<MyImages*>(ptrImage_A);
	 *
	 *  http://www.cplusplus.com/doc/tutorial/typecasting/
	 */
	Image_I* getImage();

	GLUTWindowImage* getGLUTWindowImage();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    protected:
	// Tools
	GLUTWindowImage* ptrGLUTImageWindow;
	GLImageDisplayable* ptrGLImageDisplayable;
	GLImageFactory_I* ptrImageFactory;
    };

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
