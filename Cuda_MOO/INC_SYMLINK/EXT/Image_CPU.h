#ifndef CORE_HEADER_CPU_IMAGE_CPU_H_
#define CORE_HEADER_CPU_IMAGE_CPU_H_

#include <GL/glew.h>

#include "Image_A.h"
#include "cudaType_CPU.h"
#include "DomaineMath_CPU.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*	Predefined Image		*|
 \*-------------------------------------*/

namespace cpu
    {
    typedef Image_A<uchar4,RGBA,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_RGBA_uchar4;
    typedef Image_A<uchar3, RGB,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_RGB_uchar3;
    typedef Image_A<uchar, GRAY,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_GRAY_uchar;

    typedef Image_A<uchar4, HSBA,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_HSBA_uchar4;
    typedef Image_A<uchar3, HSB,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_HSB_uchar3;
    typedef Image_A<unsigned char, HUE,GL_UNSIGNED_BYTE,cpu::DomaineMath> Image_HUE_uchar;

    typedef Image_A<float4, RGBA,GL_FLOAT,cpu::DomaineMath> Image_RGBA_float4;
    typedef Image_A<float3, RGB,GL_FLOAT,cpu::DomaineMath> Image_RGB_float3;
    typedef Image_A<float, GRAY,GL_FLOAT,cpu::DomaineMath> Image_GRAY_float;

    typedef Image_A<float4, HSBA,GL_FLOAT,cpu::DomaineMath> Image_HSBA_float4;
    typedef Image_A<float3, HSB,GL_FLOAT,cpu::DomaineMath> Image_HSB_float3;
    typedef Image_A<float, HUE,GL_FLOAT,cpu::DomaineMath> Image_HUE_float;
    }

#endif 

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
