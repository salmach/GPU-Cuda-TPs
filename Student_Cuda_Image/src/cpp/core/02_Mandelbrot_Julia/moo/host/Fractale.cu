#include "Fractale.h"
#include "FractaleMath.h"
#include "MandelbrotMath.h"

#include <iostream>

using std::cout;
using std::endl;


Fractale::Fractale(const Grid& grid,uint w, uint h, const DomaineMath& domaineMath) :
	Animable_I<uchar4>(grid,w, h, "Fractale_Cuda_RGBA_uchar4", domaineMath), variateurAnimation(Interval<int>(20, 120), 1)
    {
    // Inputs
    this->n = n;

    // Tools
    this->t = 0;
    }

/**
 * Override
 */
void Fractale::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

__device__
void Fractale::workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, FractaleMath* ptrFractaleMath)
    {
    // (i,j) domaine ecran dans N2
    // (x,y) domaine math dans R2

    double x;
    double y;
    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

    // float t=variateurAnimation.get();

    ptrFractaleMath->colorXY(ptrColorIJ, x, y); // in [01]
    }


Fractale::~Fractale(){}

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

