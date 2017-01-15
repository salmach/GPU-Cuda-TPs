#pragma once

#include "FractaleMath.h"
#include "cudaTools.h"
#include "Variateur_GPU.h"
#include "Animable_I_GPU.h"
#include "MathTools.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
//Animable_I
class Fractale: public Animable_I<uchar4>
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Fractale(const Grid& grid, uint w, uint h, const DomaineMath& domaineMath);

	__device__
	void workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, FractaleMath* ptrFractaleMath);

	virtual ~Fractale(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    protected:

	virtual void animationStep();

	uint n;
	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	Variateur<int> variateurAnimation;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
