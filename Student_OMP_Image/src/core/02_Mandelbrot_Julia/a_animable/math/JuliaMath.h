#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

class JuliaMath : public FractaleMath
    {

    public:
	JuliaMath(uint n) : FractaleMath(n)
	{
	}


//    public:
//	JuliaMath(uint n) :
//	calibreur(Interval<float>(0, 120), Interval<float>(0, 1))
//	{
//	this->n = n;
//	}

    private:
    	int calculIndice(float x, float y)
    	    {

    	    float c1 = -0.745 ;
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
