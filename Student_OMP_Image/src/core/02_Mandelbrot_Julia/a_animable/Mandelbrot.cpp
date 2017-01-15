#include "Fractale.h"
#include "FractaleMath.h"
#include "MandelbrotMath.h"
#include "Mandelbrot.h"


#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;

Mandelbrot::Mandelbrot(uint w, uint h, const DomaineMath& domaineMath): Fractale(w,h,domaineMath){}
Mandelbrot::~Mandelbrot(){}

void Mandelbrot::processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // FractaleMath MandelbrotMath(t); // ici pour preparer cuda
    MandelbrotMath MandelbrotMath(t);

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[
	    workPixel(&ptrTabPixels[s], i, j, domaineMath, &MandelbrotMath);
	    }
	}
    }

void Mandelbrot::processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    MandelbrotMath MandelbrotMath(t); // ici pour preparer cuda

    const int WH = w * h;

#pragma omp parallel
	{
	const int NB_THREAD = OmpTools::getNbThread(); // dans region parallel
	const int TID = OmpTools::getTid();

	int i;
	int j;

	int s = TID; // in [0,...
	while (s < WH)
	    {
	    IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[

	    workPixel(&ptrTabPixels[s], i, j, domaineMath, &MandelbrotMath);

	    s += NB_THREAD;
	    }
	}

    }
