#ifndef DEF_Julia
#define DEF_Julia

#pragma once

#include "FractaleMath.h"
#include "Fractale.h"

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"
using namespace cpu;


//Animable_I
class Julia: public Fractale
    {

    public:

	Julia(uint w, uint h, const DomaineMath& domaineMath);

	virtual ~Julia(void);

    private:


	/**
	 * Call periodicly by the api
	 */
	virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
#endif
