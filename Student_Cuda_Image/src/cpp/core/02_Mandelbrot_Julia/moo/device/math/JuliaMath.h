#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_GPU.h"
#include "ColorTools_GPU.h"
using namespace gpu;

class JuliaMath: public FractaleMath
    {

    public:
	__device__ JuliaMath(uint n) :
		FractaleMath(n)
	    {
	    }

	__device__
	 virtual ~JuliaMath()
	    {
	    }

	__device__
	void colorXY(uchar4* ptrColor, float x, float y)
	    {
	    int k = calculIndice(x, y); 	    //k indice
	    //int k = f(x, y);
	    //int k = 56;
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

	__device__
	void workonPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath)
	    {
	    // (i,j) domaine ecran dans N2
	    // (x,y) domaine math dans R2

	    double x;
	    double y;
	    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

	    // float t=variateurAnimation.get();

	    colorXY(ptrColorIJ, x, y); // in [01]
	    }

	__device__
	int calculIndice(float x, float y)
	    {

	    float c1 = -0.745;
	    float c2 = 0.1;
	    float a = x;
	    float b = y;
	    int i = 0;

	    for (i = 0; i <= n; i++)
		{
		float aCopy = a;
		a = ((a * a) - (b * b)) + c1;
		b = 2 * aCopy * b + c2;


		if (isDivergent(a, b))
		    {
		    return i;
		    }
		}
	    return i;
	    }


    };
