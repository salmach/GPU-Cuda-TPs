#ifndef DEF_JuliaProvider
#define DEF_JuliaProvider

#pragma once

#include "Animable_I_CPU.h"
#include "Provider_I_CPU.h"

using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class JuliaProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~JuliaProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	Animable_I<uchar4>* createAnimable(void);

	Image_I* createImageGL(void);

    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

#endif
