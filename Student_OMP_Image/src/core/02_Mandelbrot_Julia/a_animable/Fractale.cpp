#include "Fractale.h"
#include "FractaleMath.h"
#include "MandelbrotMath.h"

#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

Fractale::Fractale(uint w, uint h, const DomaineMath& domaineMath) :
	Animable_I<uchar4>(w, h, "Fractale_OMP_rgba_uchar4", domaineMath), variateurAnimation(Interval<int>(20, 120), 1)
    {
    // Input
    //this->n = n;

    // Tools
    this->t = 20;					// protected dans super classe Animable
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    // OMP
    cout << "\n[Fractale] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

Fractale::~Fractale(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void Fractale::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Override (code naturel omp)
 */

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * i in [0,h[
 * j in [0,w[
 *
 * code commun a:
 * 	- entrelacementOMP
 * 	- forAutoOMP
 */
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

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

