#include "Fractale.h"
#include "FractaleMath.h"
#include "JuliaMath.h"
#include "Julia.h"


#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;

Julia::Julia(uint w, uint h, const DomaineMath& domaineMath): Fractale(w,h,domaineMath){}
Julia::~Julia(){}

void Julia::processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // FractaleMath JuliaMath(t); // ici pour preparer cuda
    JuliaMath JuliaMath(t);

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[
	    workPixel(&ptrTabPixels[s], i, j, domaineMath, &JuliaMath);
	    }
	}
    }

void Julia::processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    JuliaMath JuliaMath(t); // ici pour preparer cuda

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

	    workPixel(&ptrTabPixels[s], i, j, domaineMath, &JuliaMath);

	    s += NB_THREAD;
	    }
	}

    }
