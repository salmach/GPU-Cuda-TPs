#ifndef CUDABUFFEROBJECT_H_
#define CUDABUFFEROBJECT_H_

#include "envGLImageCudas.h"
#include <GL/glew.h>
#include "cuda.h"
#include "cuda_runtime.h"
#include "cuda_gl_interop.h" //link between GL and Cuda

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Utility class to handle the binding with cudaGraphicsResource and OpenGL
 */
class CBI_GLIMAGE_CUDA CudaBufferObject
    {
	/*--------------------------------------*\
 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	CudaBufferObject(GLuint bufferId);


	virtual ~CudaBufferObject();

    private :

	CudaBufferObject(const CudaBufferObject& source);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public :

	template<typename T>
	void map(T** ptrDevMappedBuffer,size_t* bufferSize,cudaStream_t stream = 0);

	void map(void** ptrDevMappedBuffer,size_t* bufferSize,cudaStream_t stream=0);

	/**
	 * Tell to cuda that we finish with pixels
	 */
	void unMap(cudaStream_t stream = 0);

	/**
	 * memset to 0 on the mapped resource
	 */
	void memset0(cudaStream_t stream = 0);

    private :

	/**
	 * Disallow
	 * a=b;
	 */
	CudaBufferObject& operator=(const CudaBufferObject& b);

    private:

	// Inputs
	GLuint bufferId;

	// Tools
	cudaGraphicsResource* ptrCudaBufferResource;
    };


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		template		*|
 \*-------------------------------------*/

template<typename T>
void CudaBufferObject::map(T** ptrDevMappedBuffer,size_t* bufferSize,cudaStream_t stream)
    {
    map((void**)ptrDevMappedBuffer,bufferSize,stream);
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
