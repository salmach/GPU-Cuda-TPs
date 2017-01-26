#ifndef GLUT_IMAGE_VIEWERS_GPU_H
#define GLUT_IMAGE_VIEWERS_GPU_H

#include "cuda.h"
#include "cuda_runtime.h"

#include "envImageFreeGlutCuda.h"
#include "GLUTImageViewers_A.h"
#include "GLImageFactory_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_IMAGE_FREE_GLUT_CUDA GLUTImageViewers: public GLUTImageViewers_A
	{

	    /*--------------------------------------*\
	     |*		Constructor		    *|
	     \*-------------------------------------*/

	public:

	    GLUTImageViewers(Image_I* ptrImage,ImageOption imageOption=ImageOption(),int pxFrame = 0, int pyFrame = 0,cudaStream_t stream = 0);


	    /*--------------------------------------*\
	     |*		Destructor		*|
	     \*-------------------------------------*/

	    virtual ~GLUTImageViewers();

	};
    }
#endif
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

