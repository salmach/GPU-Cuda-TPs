#pragma once

#include "FractaleMath.h"
#include "JuliaMath.h"
#include "Fractale.h"

#include "Variateur_GPU.h"
#include "Animable_I_GPU.h"
using namespace gpu;

//Animable_I
class Julia: public Fractale
    {

    public:

	Julia(const Grid& grid,uint w, uint h, const DomaineMath& domaineMath);
	virtual ~Julia(void);

	void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);

	__device__
	void workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, JuliaMath* ptrJuliaMath);


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
    };
