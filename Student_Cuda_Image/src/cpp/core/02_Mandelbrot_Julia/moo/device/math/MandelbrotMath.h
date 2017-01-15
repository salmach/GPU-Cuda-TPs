#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_GPU.h"
#include "ColorTools_GPU.h"
using namespace gpu;

class MandelbrotMath : public FractaleMath
    {

    public:
	__device__
	MandelbrotMath(uint n) : FractaleMath(n)
	{	}


    	__device__
    	 virtual ~MandelbrotMath() {}


	__device__
	virtual  int calculIndice(float x, float y)
    	    {
	    /*
    	    float a = 0;
    	    float b = 0;
    	    int i = 0;

    	    for (i = 0; i <= n; i++)
    		{
    		float aCopy = a;
    		a = ((a * a) - (b * b)) + x;
    		b = 2 * aCopy * b + y;

    		if (isDivergent(a, b))
    		    {
    		    return i;
    		    }
    		}
    	    return i;
*/
	return 77;
    	    }

    };
