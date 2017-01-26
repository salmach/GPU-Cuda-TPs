#ifndef IMAGE_GPU_H_
#define IMAGE_GPU_H_

#include <GL/glew.h>
#include "Image_A.h"
#include "cuda.h"
#include "cuda_runtime.h"
#include "DomaineMath_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*	Predefined Image		*|
 \*-------------------------------------*/

namespace gpu
    {
    typedef Image_A<uchar4,RGBA,GL_UNSIGNED_BYTE,gpu::DomaineMath> Image_RGBA_uchar4;
    typedef Image_A<uchar3, RGB,GL_UNSIGNED_BYTE,gpu::DomaineMath> Image_RGB_uchar3;
    typedef Image_A<unsigned char, GRAY,GL_UNSIGNED_BYTE,gpu::DomaineMath> Image_GRAY_uchar;
    typedef Image_A<uchar3, HSB,GL_UNSIGNED_BYTE,gpu::DomaineMath> Image_HSB_uchar3;
    typedef Image_A<uchar4, HSBA,GL_UNSIGNED_BYTE,gpu::DomaineMath> Image_HSBA_uchar4;
    typedef Image_A<uchar3, HUE,GL_UNSIGNED_BYTE,gpu::DomaineMath> ImageHue;

    typedef Image_A<float4, RGBA,GL_FLOAT,gpu::DomaineMath> Image_RGBA_float4;
    typedef Image_A<float3, RGB,GL_FLOAT,gpu::DomaineMath> Image_RGB_float3;
    typedef Image_A<float, GRAY,GL_FLOAT,gpu::DomaineMath> Image_GRAY_float;

    typedef Image_A<float4, HSBA,GL_FLOAT,gpu::DomaineMath> Image_HSBA_float4;
    typedef Image_A<float3, HSB,GL_FLOAT,gpu::DomaineMath> Image_HSB_float3;
    typedef Image_A<float, HUE,GL_FLOAT,gpu::DomaineMath> Image_HUE_float;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
