#ifndef DEF_FRACTALEMATH
#define DEF_FRACTALEMATH

#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class FractaleMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:
	FractaleMath(uint n) :
		calibreur(Interval<float>(0, 120), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	FractaleMath
	// 	calibreur
	// 	IntervalF

	virtual ~FractaleMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	void colorXY(uchar4* ptrColor, float x, float y)
	    {

	    int k = calculIndice(x, y); 	    //k indice

	    if (k < n)
		{
		float hue01 = k;
		calibreur.calibrer(hue01);

		ColorTools::HSB_TO_RVB(hue01, ptrColor); // update color
		}
	    else
		{
		ptrColor->x = 0;
		ptrColor->y = 0;
		ptrColor->z = 0;
		}
	    ptrColor->w = 255; // opaque
	    }

    protected:
	virtual int calculIndice(float x, float y) = 0;


    protected:
	bool isDivergent(float x, float y)
	    {
	    return (((x * x) + (y * y)) > 4);
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    protected:

	// Input
	uint n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
#endif
