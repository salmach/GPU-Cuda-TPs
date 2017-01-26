#ifndef GLIMAGEFACTORY_CPU_H_
#define GLIMAGEFACTORY_CPU_H_

#include "GLImageFactory_I.h"
#include "envGLImage.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {
    class CBI_GLIMAGE GLImageFactory: public GLImageFactory_I
	{

	public:

	    virtual ~GLImageFactory()
		{
		//Rien
		}

	    GLImage_I* create();

	};

    }

#endif //GLIMAGEFACTORY_CPU_H_

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
