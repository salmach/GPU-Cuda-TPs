#include "Mandelbrot.h"
#include "MandelbrotMath.h"
#include "Indice2D.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;


__global__ void MandelbrotKernel(uchar4* ptrDevPixels, uint w, uint h,const DomaineMath &domaineMath, uint n, float t)
    {

    MandelbrotMath mandelbrotMath = MandelbrotMath(n);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH = w * h;

    int i;// in [0,h[
    int j;// in [0,w[

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &i, &j); // update (i, j)

	// (i,j) domaine ecran
	mandelbrotMath.workonPixel(&ptrDevPixels[s], i, j, domaineMath);

	s += NB_THREAD;
	}

	}
