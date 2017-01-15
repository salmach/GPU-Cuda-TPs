#ifndef DEF_FRACTALE
#define DEF_FRACTALE

#pragma once

#include "FractaleMath.h"

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"
using namespace cpu;

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

	Fractale(uint w, uint h, const DomaineMath& domaineMath);

	virtual ~Fractale(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    protected:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)=0;

	/**
	 * Call periodicly by the api
	 */
	virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)=0;

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

    protected:

	/**
	 * i in [0,h[
	 * j in [0,w[
	 *
	 * code commun a:
	 * 	- entrelacementOMP
	 * 	- forAutoOMP
	 */
	void workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, FractaleMath* ptrFractaleMath);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	uint n;

	// Tools
	Variateur<int> variateurAnimation;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
#endif
