#ifndef GLIMAGEFACTORY_GPU_H_
#define GLIMAGEFACTORY_GPU_H_

#include "cuda.h"
#include "cuda_runtime.h"
#include "GLImageFactory_I.h"
#include "envGLImageCudas.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_GLIMAGE_CUDA GLImageFactory: public GLImageFactory_I
	{
	public:

	    GLImageFactory(cudaStream_t stream = 0);

	    virtual ~GLImageFactory()
		{
		//Rien
		}

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	public:

	    /**
	     * Create new gpu::GLImage with factory cuda stream
	     */
	    GLImage_I* create();

	    /*--------------------------------------*\
	     |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Input
	    cudaStream_t stream;
	};
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
