#ifndef GLUT_IMAGE_VIEWERS_CPU_H
#define GLUT_IMAGE_VIEWERS_CPU_H

#include "envImage_FreeGlut.h"
#include "GLUTImageViewers_A.h"
#include "GLImageFactory_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {

    class CBI_IMAGE_FREE_GLUT GLUTImageViewers : public GLUTImageViewers_A
	{
	    /*--------------------------------------*\
	 |*		Constructor	*|
	     \*-------------------------------------*/

	public:

	    GLUTImageViewers(Image_I* ptrImage,ImageOption imageOption=ImageOption(),int pxFrame = 0, int pyFrame = 0);
	};

    }

#endif
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

