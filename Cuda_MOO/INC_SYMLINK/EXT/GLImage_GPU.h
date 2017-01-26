#ifndef GLIMAGE_GPU_H_
#define GLIMAGE_GPU_H_

#include "envGLImageCudas.h"

#include "GLImage_A.h"
#include "CudaBufferObject.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace gpu
    {
    class CBI_GLIMAGE_CUDA GLImage : public GLImage_A
	{
	    /*--------------------------------------*\
	     |*		Constructor		*|
	     \*-------------------------------------*/

	public:

	    GLImage(cudaStream_t stream = 0);

	    virtual ~GLImage();

	    /*--------------------------------------*\
	     |*		Surcharge		*|
	     \*-------------------------------------*/

	public:

	    void init(Image_I* ptrImage);

	    void release();

	protected:

	    // Override
	    void fillPbo(Image_I* ptrImage);

	   /*--------------------------------------*\
	     |*		Get			*|
	     \*-------------------------------------*/

	    inline cudaStream_t getStream() const
		{
		return stream;
		}

	    /*--------------------------------------*\
	     |*		Set			*|
	     \*-------------------------------------*/

	    void setStream(cudaStream_t stream);

	public:

	    /*--------------------------------------*\
	 |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    cudaStream_t stream;
	    CudaBufferObject* ptrCudaBufferObject;
	};

    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
