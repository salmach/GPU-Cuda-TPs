#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

class MandelbrotMath : public FractaleMath
    {

    public:
	MandelbrotMath(uint n) : FractaleMath(n)
	{
	}


//    public:
//	MandelbrotMath(uint n) :
//	calibreur(Interval<float>(0, 120), Interval<float>(0, 1))
//	{
//	this->n = n;
//	}

    private:
    	int calculIndice(float x, float y)
    	    {

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

    	    }




    };
