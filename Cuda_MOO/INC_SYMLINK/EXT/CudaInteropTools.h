#ifndef CUDA_INTEROP_TOOLS_H
#define CUDA_INTEROP_TOOLS_H

//#include "GLImageCudas.h" //include ImageCudas
#include "envGLImageCudas.h"
#include <GL/glew.h>
#include "cuda.h"
#include "cuda_gl_interop.h" //link between GL and Cuda
/**
 * Informations :
 *
     * http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__OPENGL.html#group__CUDART__OPENGL
 */
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

CBI_GLIMAGE_CUDA void initCudaForGLInterop(int deviceId = 0);

/**
 * stream avec lequelle il synchronise
 */
CBI_GLIMAGE_CUDA cudaGraphicsResource* linkWithCuda(GLuint pboID, cudaStream_t stream = 0);

/**
 * stream avec lequelle il synchronise
 */
CBI_GLIMAGE_CUDA void unLinkWithCuda(cudaGraphicsResource* cudaRessource);

/*
 * Get Pixels from device to use with Cuda !
 */
CBI_GLIMAGE_CUDA void mapDevicePixels(cudaGraphicsResource* cudaRessource, uchar4** devPixels, size_t* size, cudaStream_t stream = 0);

/**
 * Tell to cuda that we finish with pixels
 */
CBI_GLIMAGE_CUDA void unMapDevicePixels(cudaGraphicsResource *cudaRessource, cudaStream_t stream = 0);

CBI_GLIMAGE_CUDA void resetDevicePixel(cudaGraphicsResource* cudaRessource, cudaStream_t stream = 0);

#endif

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

