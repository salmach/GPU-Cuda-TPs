#pragma once

#include "FractaleMath.h"
#include "Fractale.h"

#include "cudaTools.h"
#include "MathTools.h"

#include "Variateur_GPU.h"
#include "Animable_I_GPU.h"
using namespace gpu;


//Animable_I
class Mandelbrot: public Fractale
    {

    public:

	Mandelbrot(const Grid& grid,uint w, uint h, const DomaineMath& domaineMath);

	void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);

	__device__
	void workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, FractaleMath* ptrFractaleMath);

	virtual ~Mandelbrot(void);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
