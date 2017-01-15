#ifndef DEF_MANDELBROT
#define DEF_MANDELBROT

#pragma once

#include "FractaleMath.h"
#include "Fractale.h"

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"
using namespace cpu;


//Animable_I
class Mandelbrot: public Fractale
    {

    public:

	Mandelbrot(uint w, uint h, const DomaineMath& domaineMath);

	virtual ~Mandelbrot(void);

    private:


	/**
	 * Call periodicly by the api
	 */
	virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
#endif
