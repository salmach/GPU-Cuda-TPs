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

class DamierHueFloatMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DamierHueFloatMath(uint n) :
		calibreur(Interval<float>(-1, 1), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	virtual ~DamierHueFloatMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void colorXY(float* ptrColor, float x, float y, float t)
	    {
	    float z = f(x, y, t);

	    calibreur.calibrer(z);
	    float hue01 = z;

	    *ptrColor= hue01;
	    }

    private:

	float f(float x, float y, float t)
	    {
	    return sin(x * n + t) * cos(y * n + t);
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	uint n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
