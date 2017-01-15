#pragma once

#include "cudaTools.h"

#include "Provider_I_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RayTracingProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~RayTracingProvider()
	    {
	    // Rien
	    }
	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	virtual Animable_I<uchar4>* createAnimable(void);

	virtual Image_I* createImageGL(void);


    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

